// Todo: Add coercibility checks
// Add string literals

/* TODO: SET INDICES and #defines PROPERLY */

%{
#include "calc.h"  /* Contains definition of `symrec'        */
#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "func.h"
#include "gramm.h"

#define DEFAULT_OUT "int.out"

int vtype;
FILE *outfile;

int next_quad;
int label_no;
int patches[MAX_NEST_DEPTH];
int patch_idx;

struct pair cur_loop;

struct bigop {
    int op;
    char str[3];
};

int BIGOPS_NUM;
struct list *nested;
struct scope_type scope;

struct func_rec *active_func;

// Builtin type info.
void init_globals();

%}

%union {
double  val;  /* For returning numbers.                   */  
char *id_name;
char *t_name;
symrec *sym;
struct {
  char *name;
  struct type type;
} sym_npt; // stands for name and pointer types
struct {
  int type;
  int val;
} constant;
struct expr_type e;
struct type type;
int patch;
struct pair dual_patch;
struct loop_type loop;
int ttype;
struct memb_list *tlist;
struct list *l;
struct type *alias_type;
}

%token OR_OP AND_OP EQ_OP NE_OP
%token LE_OP GE_OP LSHFT_OP RSHFT_OP INC_OP DEC_OP

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN
%token SIZEOF


%token <e> CONSTANT        /* Simple double precision number   */
%token <id_name> IDENTIFIER/* Variable and Function            */
%token <alias_type> ALIAS_NAME

%type <id_name> func_name
%type <patch> if_clause
%type <dual_patch> else_clause 
%type <loop> while_clause
%type <e> expr primary_expr opt_init function_call
%type <type> type_name compound_type
%type <l> var_dlist var_definition actual_params actual_params_list
%type <sym_npt> symbol_name
%type <ttype> type_type
%type <t_name> opt_ctype_name ctype_name;
%type <tlist> opt_member_decl_list member_decl_list member_decl id_list
%type <e> indexing

// %precedence mult_op
// %precedence ad_op
%expect 1
%left ','
%right '='
%left OR_OP
%left AND_OP
%left '&' 
%left '^'
%left '|'
%left EQ_OP NE_OP
%left '<' '>' LE_OP GE_OP
%left LSHFT_OP RSHFT_OP
%left '-' '+'
%left '*' '/' '%'
%left DEREF
%right INC_OP DEC_OP 
%right ')'
%right '!' '~'
%left UMINUS     /* Negation--unary minus */
%left '.'
%left '['

%nonassoc IF
%nonassoc ELSE

/* Grammar follows */

%%


input :   /* empty */
      | input global_statement
      ;

global_statement  :  declaration_statement {}
                  |  type_definition {}
                  |  function_definition {}
                  ;

body  :  body_statement body {}
      |  /* empty */
      ;

body_statement    : declaration_statement {}
                  | jump_statement {}
                  | expression_statement {}
                  | error { yyerrok; }
                  | selection_statement {}
                  | iterative_statement {}
                  | block_statement {}
                  | label_stmt {}
                  | return_statement {}
                  ;

// User defined label
label_stmt: IDENTIFIER ':' { fprintf(outfile, "%s: ", $1); }
          ;

return_statement  : RETURN expr ';' { out_return(&$2); }
                  | RETURN ';' { out_return(NULL); }
                  ;

/* TODO: prototypes */
/* ERROR HANDLING syntax vs. semantic errors */
function_definition  : func_head block_statement 
            {
              active_func = NULL;
              scope.level--;
              printf("165\n");
              out_end_func();  
              printf("167\n");      
            }
            ;

func_head : res_id begin_params '(' param_decl_list ')' end_params
            {
              active_func->label = label_no;
              out_begin_func();
            }
          ;

begin_params : /* empty */ { printf("178\n");scope.level++; scope.label = label_no; }
            ;
end_params : /* empty */ { printf("180\n");scope.level--; }
            ;

res_id  : type_name IDENTIFIER
          {
            struct func_rec *func;
            if (func = search_func($2)) {
              if (func->defined)
                error("Redefinition of function");
              /* Check if the prot. is not consistent with head */
              active_func = func;
            }
            else {
              active_func = create_func($2, $1);
            }
          }
        ;

param_decl_list : param_list
                | /* empty */ { printf("199\n"); }
                ;

param_list  : param_decl
            | param_decl ',' param_list
            ;

param_decl  : type_name symbol_name
              {
                struct array_type arr;
                symrec *sym = getsym(active_func, $2.name, scope);
                if (sym && sym->scope.level == scope.level)
                  error("Redefinition of parameter");
                sym = putsym(active_func, $2.name, $1, scope);
                create_param(active_func, sym);

                if (sym->type.ttype == INCOMPL_TYPE) {
                  arr = $2.type.array;
                  if ($1.ttype == INCOMPL_TYPE)
                    error("incomplete type for varibale");
                  sym->type = $1;
                  sym->type.array = arr;
                }
                else if (sym->type.ttype == PTR_TYPE) {
                  struct type *t = sym->type.val.ptr_to;
                  // Travese the list of ptr types
                  while (t->ttype == PTR_TYPE)
                    t = t->val.ptr_to;
                  // Set the type of the last node to the basic
                  // or compound type that is type_name
                  if (t->ttype == INCOMPL_TYPE) {
                    arr = (*t).array;
                    *t = $1;
                    (*t).array = arr;
                  }
                }
                  // TODO: Relloc in the entire ptr_to linked list
                  // sym->type.array.dimen = realloc(sym->type.array.dimen, sym->type.array.n * sizeof(int));
              }
            ;

/* TODO: Differentiate between stmts inside 
and outside functions */
block_statement : begin_sub '{' body '}' end_sub
                ;

begin_sub :   /* eps */
              {
                scope.label = label_no;
                // Push scope info onto stack
                list_prepend_elem(&nested, 
                  list_create_elem((void *)label_no));
                scope.level++;
                out_label();
              }
          ;

end_sub   :   /* eps */
              {
                printf("257\n");
                void *data = list_pop_front(&nested);
                printf("259\n");
                printf("%d\n", nested);
                scope.label = (int) data;
                printf("262\n");

                // delsym_scope(scope.level);
                scope.level--;
                printf("267\n");

              }
          ;

type_definition : aliasing ';'
                | compound_type ';'
                ;

// Forward declarations of structs ignored for now
/* TODO: Allow definitions of recursive structs pointers by 
 * combining the two */
/* TODO: Check for duplicate members */
compound_type   : type_type opt_ctype_name '{' member_decl_list '}'
                    { 
                      printf("nam1e %s\n", $2);
                      if (get_struct($2))
                        error("Redefinition of struct");
                      /* TODO: Differentiate b/w STRUCT and
                       * UNION */
                      $$.val.stype = create_struct($2, $4, false);
                      $$.ttype = COMPOUND_TYPE;
                      SET_NOT_ARRAY($$);
                      // If it is not null string
                      if ($2[0])
                        free($2);
                    }
                | type_type ctype_name
                  {
                    printf("name2 %s\n", $2);

                    struct struct_type *s = get_struct($2);
                    if (!s)  {
                      // Forward declaration
                      $$.val.stype = create_struct($2, NULL, true);
                      $$.ttype = INCOMPL_TYPE;                      
                    }
                    else {
                      $$.ttype = COMPOUND_TYPE;
                      $$.val.stype = s;                    
                    }
                    SET_NOT_ARRAY($$);
                    free($2);
                  }
                ;

type_type : STRUCT { $$ = STRUCT_TAG; } 
          | UNION  { $$ = UNION_TAG; }
          ;

ctype_name  : IDENTIFIER 
              {
                copy_name(&$$, $1);
                printf("%s\n", $$);
              }
            ;

opt_ctype_name: /* empty */ { $$ = ""; }
            | ctype_name  { $$ = $1; }
            ; 

/* TODO: Add case when the member list can 
also be empty */
member_decl_list:  member_decl opt_member_decl_list
              {
                // Join the two lists. 
                struct memb_list *mem = $1;
                while (mem->next)
                  mem = mem->next;
                mem->next = $2;
                $$ = $1;
              }

           ;

opt_member_decl_list: /* empty */ { $$ = NULL; }
                    | member_decl_list { $$ = $1; }
                    ;

member_decl : type_name id_list ';'
              {
                // Set types for all members
                struct memb_list *mem = $2;
                if (size_of($1) == -1)
                  error("member has incomplete type");
                while (mem) {
                  mem->type = $1;
                  mem = mem->next; 
                }
                $$ = $2;
              }
            ;

id_list         : IDENTIFIER
                  {
                    $$ = create_member($1, NULL);
                  }
                | IDENTIFIER ',' id_list
                  {
                    $$ = create_member($1, $3); 
                  }
                ;

aliasing  : TYPEDEF type_name IDENTIFIER
            { 
              struct type *t;
              if (t = get_alias($3))  {
                // Check type equivalence properly
                if (!is_equiv(*t, $2))
                  error("Conflicting types for typedef");
              }
              else 
                create_alias($3, $2);
            }
          ;


expression_statement  :  expr ';'
                      |  /*empty*/  ';'
                      ;


jump_statement  : CONTINUE ';'
                  { 
                    printf("%d", cur_loop.label);
                    if (cur_loop.label == -1)
                      error("continue statement not within a loop");
                    out_jmp(NULL, &cur_loop.label, JUMP_LABEL_NUMBER); 
                  }
                | BREAK ';' 
                  { 
                    if (cur_loop.label == -1)
                      error("break statement not within a loop or a switch");
                    out_jmp(NULL, &cur_loop.patch, JUMP_PATCH); 
                  }
                | GOTO IDENTIFIER ';' { out_jmp(NULL, (void *)$2, JUMP_LABEL_NAME); } 
                ;

iterative_statement :  while_loop
                    // |  for_loop
                    // |  do_while_loop ';'
                    ;

while_loop          : while_clause body_statement
                      {
                        out_jmp(NULL, &($1.this.label), JUMP_LABEL_NUMBER);
                        int label = label_no;
                        out_label();
                        backpatch(label, $1.this.patch);
                        cur_loop = $1.prev;
                      }
                    ;

while_clause        : WHILE '(' expr ')'
                      {
                        $$.prev = cur_loop; 
                        $$.this.label = label_no;
                        out_label();
                        $$.this.patch = out_jmp(&$3, (void *)NULL, 0);
                        cur_loop = $$.this;
                      }
                    ;

selection_statement  :  if_clause body_statement {
                          int l_no = label_no;
                          out_label();
                          backpatch(l_no, $1); 
                        }
                     | if_clause body_statement else_clause body_statement
                       {
                          int l_no = label_no;
                          out_label();
                          backpatch($3.label, $1);
                          backpatch(l_no, $3.patch);
                       }
                     ;

if_clause   : IF '(' expr ')' {
                // returns patch number
                $$ = out_jmp(&$3, (void *)NULL, 0);
                printf("If clause done\n");
              }
            ;

else_clause   :  ELSE {
                    $$.patch = out_jmp(NULL, NULL, 0);
                    $$.label = label_no;
                    out_label();
                 }
              ;

declaration_statement : type_name var_dlist ';' 
                        {
                          struct list *node = $2;
                          struct symrec *sym;
                          /* TODO: Check for completeness of 
                            type here */
                          if ($1.ttype == UNDEF_TYPE)
                            error("incomplete type");
                          if (is_void_type($1))
                            error("Void type varible declaration");

                          // Backpatch
                          while (node) {
                            sym = (symrec *) node->data;
                            struct array_type arr = sym->type.array;
                            if (sym->type.ttype == INCOMPL_TYPE) {
                              if ($1.ttype == INCOMPL_TYPE)
                                error("incomplete type for varibale");
                              sym->type = $1;
                            }
                            else if (sym->type.ttype == PTR_TYPE) {
                              struct type *t = sym->type.val.ptr_to;
                              // Travese the list of ptr types
                              while (t->ttype == PTR_TYPE)
                                t = t->val.ptr_to;
                              // Set the type of the last node to the basic
                              // or compound type that is type_name
                              if (t->ttype == INCOMPL_TYPE)
                                *t = $1;
                            }
                            sym->type.array = arr;
                            // TODO: Relloc in the entire ptr_to linked list
                            sym->type.array.dimen = realloc(sym->type.array.dimen, sym->type.array.n * sizeof(int));
                            node = node->next;
                          }
                        }
                      ;
          
var_dlist : var_definition ',' var_dlist { printf("Entering var_dlist"); list_prepend_elem(&$3, $1); $$ = $3; printf("Leaving var_dlist") }
          | var_definition { $$ = $1; }
          ;


var_definition  : symbol_name opt_init 
                  {
                    printf("495\n");
                    symrec *rec = getsym(active_func, $1.name, scope);
                    if (rec && rec->scope.level == scope.level) {
                      error("Redefinition of symbol");
                    }
                    printf("500\n");

                    rec = putsym(active_func, $1.name, $1.type, scope);
                    printf("503\n");

                    $$ = list_create_elem(rec);  
                    printf("506\n");

                    
                    // Assign result of expr to vaiable
                    // This is should be delayed to after the 
                    // type backpatch to check coercibility
                    if ($2.type.ttype != UNDEF_TYPE) {
                        out_assign($1.name, $2);
                    }
                    free($1.name);
                    printf("510\n");
                  }
                ;

// TAKE CARE OF PASSING BOTH NAME and 
// TYPE UP the TREE
symbol_name : IDENTIFIER 
              {
                copy_name(&$$.name, $1);
                // Create a new symbol table record
                // and assign it the thing from the old record  
                $$.type.ttype = INCOMPL_TYPE; 
                SET_NOT_ARRAY($$.type);
              }              
            /* TODO: Size decided by initializers */
            | symbol_name '[' CONSTANT ']'
              {
                struct type *t = &($1.type);
                if (const_type($3.val.const_str) != INT_TYPE)
                  error("size of array has non-integer type");
                int size = const_val($3.val.const_str);
                if (!is_array(*t)) {
                  t->array.dimen = malloc(MAX_ARRAY_DIMEN * sizeof(int));
                  t->array.n = 1;
                }
                else {
                  t->array.n++;
                }
                if (t->array.n == MAX_ARRAY_DIMEN)
                  error("Can't have more than 256 dimension array");
                t->array.dimen[t->array.n - 1] = size;
                t->array.size *= size;
                $$ = $1;
              }
            | '*' symbol_name
              {
                struct type *to = malloc(sizeof(struct type));
                *to = $2.type; // TYPE COPYING
                $$.type.ttype = PTR_TYPE;
                $$.type.val.ptr_to = to;
                SET_NOT_ARRAY($$.type);
                $$.name = $2.name;
              }
            | '(' symbol_name ')' { $$ = $2; }

          ;

/* TODO: Take care of incomplete type 
error messages for empty structs */
/* TODO: Handle array and ptr types here too */
type_name : INT { $$ = basic_types[INT_TYPE].t; }
          | FLOAT { $$ = basic_types[FLOAT_TYPE].t; }
          | CHAR { $$ = basic_types[CHAR_TYPE].t; }
          | VOID { $$ = basic_types[VOID_TYPE].t; }
          | compound_type { $$ = $1; }
          | ALIAS_NAME { $$ = *$1; }
          ;

opt_init  :  '=' expr   { printf("In opt_init"); $$ = $2; }
          | /* empty */ { $$.type.ttype = UNDEF_TYPE; }
        ;

/* TODO: array initializers, struct initializers */
primary_expr  : CONSTANT  { 
                  char *temp;
                  copy_name(&temp, $1.val.const_str);
                  $$ = create_const_expr(temp);
                  SET_NOT_DEREF($$);
                }
              | IDENTIFIER { 
                  symrec *rec = getsym(active_func, $1, scope);
                  if (!rec) {
                    error("Undefined symbol\n");
                  }
                  $$ = create_sym_expr(rec);
                  SET_NOT_DEREF($$);
                }
              | '(' expr ')' { $$ = $2; }
              | function_call { $$ = $1; }
              ;

/* function call will be a standard expr type */
function_call : func_name '(' actual_params_list ')'
                {
                  struct func_rec *func = search_func($1);
                  if (!func)
                    error("Undefined function");

                  struct list *fp = func->param_list;
                  struct list *ap = $3;

                  struct type t;
                  struct expr_type *e; int arg_num = 0;

                  while (fp && ap) {
                    arg_num++;
                    t = ((symrec *)fp->data)->type;
                    e = (struct expr_type *)ap->data;
                    if (!is_equiv(t, e->type) && !is_coercible(t, e->type))
                      error("incompatible type for argument");
                    out_param(*e);
                    fp = fp->next;
                    ap = ap->next;
                  }

                  if (fp || ap)
                    error("argument number mismatch");

                  $$.ptr = QUAD_PTR; $$.val.quad_no = next_quad;
                  $$.type = func->ret_type;
                  SET_NOT_DEREF($$);
                  out_call(func);

                  /*TODO: Free every shit*/
                }
              ;

func_name : IDENTIFIER { copy_name(&$$, $1); }

actual_params_list  : actual_params { $$ = $1; }
                    | /* empty */ { $$ = NULL; }
actual_params : expr
                {
                  struct expr_type *e = malloc(sizeof(struct expr_type));
                  *e = $1;
                  $$ = list_create_elem(e);
                }
              | expr ',' actual_params
                {
                  struct expr_type *e = malloc(sizeof(struct expr_type));
                  *e = $1;
                  list_prepend_elem(&$3, list_create_elem(e));
                  $$ = $3;
                }
              ;

// Note that basic types can be inconverted , but compound types can't
// i.e struct test t; int b = (int)t; is an error
expr    : primary_expr { $$ = $1; }
        | expr indexing { $$ = parse_indexed_expr($1, $2); }
        | expr '.' IDENTIFIER { out_member_ref($1, $3); }
        | '!' expr  { parse_unary_expr(&$$, $2, '!'); }
        | '~' expr  { parse_unary_expr(&$$, $2, '~'); }
        | '-' expr %prec UMINUS  { parse_unary_expr(&$$, $2, '-'); }
        | INC_OP expr  
          { 
            struct expr_type e = create_const_expr("1");
            parse_expr(&$$, $2, e, '+');
            if ($2.ptr != SYM_PTR) {
              printf("%d\n", $2.type);
              error("lvalue required as increment operand");
            }
            out_assign($2.val.sym->name, $$);
          }
        | DEC_OP expr
          { 
            struct expr_type e = create_const_expr("1");
            parse_expr(&$$, $2, e, '-');
            /* TODO: Think about how pointers behave here */
            if ($2.ptr != SYM_PTR) {
              error("lvalue required as increment operand");
            }
            out_assign($2.val.sym->name, $$);
          }
        | '(' type_name ')' expr
          {
            if (!is_coercible($2, $4.type))
              error("types are not coercible");
            $$.type = $2;
            $$.val.quad_no = next_quad;
            $$.ptr = QUAD_PTR;
            out_gen_quad($4);
          }
        | '*' expr %prec DEREF
          {
            /* Delayed eval */
            if (is_indexed($2) || is_derefd($2))
              $$ = get_vector_elem($2);
            if (!is_array($$.type) && !is_pointer($$.type))
              error("Attempting to dereference non-pointer");
            /* deref'd whenever used */
          }
        | expr '*' expr  { parse_expr(&$$, $1, $3, '*'); }
        | expr '/' expr  { parse_expr(&$$, $1, $3, '/'); }
        | expr '%' expr  { parse_expr(&$$, $1, $3, '%'); }
        | expr '+' expr  { parse_expr(&$$, $1, $3, '+'); }
        | expr '-' expr  { parse_expr(&$$, $1, $3, '-'); }
        | expr LSHFT_OP expr  { parse_expr(&$$, $1, $3, LSHFT_OP); }
        | expr RSHFT_OP expr  { parse_expr(&$$, $1, $3, RSHFT_OP); }
        | expr '>' expr  { parse_expr(&$$, $1, $3, '>'); }
        | expr '<' expr  { parse_expr(&$$, $1, $3, '<'); }
        | expr LE_OP expr  { parse_expr(&$$, $1, $3, LE_OP); }
        | expr GE_OP expr  { parse_expr(&$$, $1, $3, GE_OP); }
        | expr EQ_OP expr  { parse_expr(&$$, $1, $3, EQ_OP); }
        | expr NE_OP expr  { parse_expr(&$$, $1, $3, NE_OP); }        
        | expr '|' expr  { parse_expr(&$$, $1, $3, '|'); }
        | expr '^' expr  { parse_expr(&$$, $1, $3, '^'); }
        | expr '&' expr  { parse_expr(&$$, $1, $3, '&'); }
        | expr AND_OP expr  { parse_expr(&$$, $1, $3, AND_OP); }
        | expr OR_OP expr  { parse_expr(&$$, $1, $3,  OR_OP); }
        // Need to change primary_expr to general expression
        | expr '=' expr  { parse_assignment($1, $3); $$ = $1; }
        ;

indexing  : '[' expr ']'
            {
              if (is_indexed($2) || is_derefd($2))
                $$ = get_vector_elem($2);
              else
                $$ = $2;
              if (!is_int_expr($$)) // or convertible to int
                error("array subscript is not an integer");
            }
          ;
/* End of grammar */
%%

struct bigop bigops[] = {
    {OR_OP, "||"},
    {AND_OP, "&&"},
    {EQ_OP, "=="},
    {NE_OP, "!="},
    {LE_OP, "<="},
    {GE_OP, ">="},
    {LSHFT_OP, "<<"},
    {RSHFT_OP, ">>"},
    {INC_OP, "++"},
    {DEC_OP, "--"}
};

int
main ()
{
  printf("In main");
  /* TODO: Parse args properly */
  outfile = fopen(DEFAULT_OUT, "w+");
  if (!outfile) {
    printf("Error opening output file\n");
    exit(1);
  }

  init_globals();
  init_tables();

  yyparse ();
}

void
init_globals() {
  int i;
  BIGOPS_NUM = sizeof(bigops);
  // Current loop information
  cur_loop.patch = cur_loop.label = -1;
  // temporary number
  next_quad = 0;
  // label and patch system
  label_no = 1; patch_idx = 0;
  nested = NULL;
  for (i = 0; i< MAX_NEST_DEPTH; ++i)
    patches[i] = 0;
  scope.level = scope.label = scope.over = 0;
  active_func = NULL;
}

yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s\n", s);
}

void
error (char *msg) {
  printf("%d:%d: error: %s\n", lineno, colno, msg);
  fclose(outfile);
  exit(1);
}

void
warning (char *msg) {
  printf("warning: %s\n", msg);
}

struct init
{
  char *fname;
  double (*fnct)();
};


void
out_assign(char *name, struct expr_type expr) {
  char *s = NULL;
  assign_name_to_buf(&s, expr);

  fprintf(outfile, "%s = %s\n", name, s);

  free(s);
  return;
}


void 
out_gen_quad (struct expr_type e) {
  char *temp = malloc(10 * sizeof(int));
  temp_var_name(next_quad++, temp);
  out_assign(temp, e);

  free(temp);
  return;
}

int
out_jmp(struct expr_type *e, void *label, int type) {
  char *ltext, *cond, *name = NULL; int i = -1;
  int mf1 = 0;
  printf("834\n");
  if (!label) {
    // 5 spaces, temporarily so that label name can be accomodated
  printf("837\n");

    mf1 = 1;
    i = 0;
    while(i < MAX_NEST_DEPTH && i < patches[i])
      i++;
  printf("843\n");

    if (i == MAX_NEST_DEPTH)
      error("Can't nest more than 256 levels");

    make_patch_text(&ltext, i);
    patches[i] = 1;
  }
  else {
  printf("852\n");

    if (type == JUMP_LABEL_NUMBER) {
      mf1 = 1;
      make_label_text(&ltext, *((int *)label));
    }
    else if (type == JUMP_LABEL_NAME)
      ltext = (char *)label;
    else {
      // Jump to patch number
      mf1 = 1;
      make_patch_text(&ltext, *((int *) label));
  printf("864\n");


    }
  }

  printf("869\n");

  if (e) {
    cond = malloc(100 * sizeof(char));
    assign_name_to_buf(&name, *e);
    printf("Befor cond print\n");
    snprintf(cond, 100, "if ( %s == 0 )\n", name);
  printf("877\n");

    printf(cond);
  }
  else 
    cond = "";
  printf("883\n");

  fprintf(outfile, "%s goto %s\n", cond, ltext);
  printf("886\n");

  if (mf1)  {
  printf("889\n");

    free(ltext);
  printf("892\n");

  }
  if (e) {
  printf("890\n");

    free(cond);
    free(name);
  }

  printf("returning\n");

  return i;
}

void backpatch(int label, int patch) {
  int tp; int write_pos; int temp_pos;
  int cur_pos = ftell(outfile); 
  char c;
  char *ltext; 

  make_label_text(&ltext, label);
  fseek(outfile, 0, SEEK_SET);
  printf("before loop%d\n", ftell(outfile));
  while ((c = getc(outfile)) != EOF) {
    if (c != '$')
      continue;
    write_pos = ftell(outfile) - 1;
    fscanf(outfile, "%d", &tp);
    temp_pos = ftell(outfile);
    if (tp == patch) {
      fseek(outfile, write_pos, SEEK_SET);
      fprintf(outfile, "%s", ltext);
    }
    fseek(outfile, temp_pos, SEEK_SET);
  } 
  printf("after loop\n");


  fseek(outfile, cur_pos, SEEK_SET);
  patches[patch] = 0;
  free(ltext);
}


void
parse_unary_expr (struct expr_type *result, 
              struct expr_type e1, int op) {
    if (is_indexed(e1) || is_derefd(e1))
      e1 = get_vector_elem(e1);
    // Check for coercibility here
    int qno = next_quad;
    printf("911\n");

    make_two_quad(e1, op);
    printf("914\n");

    result->ptr = QUAD_PTR; 
    result->val.quad_no = qno;
    result->type = e1.type;
    SET_NOT_DEREF((*result));
    printf("913\n");
    // $$.type = MAX($1.type, $3.type);
}


void
parse_expr (struct expr_type *result, struct expr_type e1,
          struct expr_type e2, int op) {
  printf("Entering parse_expr");
    // Check for coercibility here
  if (is_indexed(e1) || is_derefd(e1))
    e1 = get_vector_elem(e1);
  if (is_indexed(e2) || is_derefd(e2))
    e2 = get_vector_elem(e2);
  printf("917");
  int qno = next_quad;
  make_quad(e1, e2, op);
  printf("920");

  result->ptr = QUAD_PTR; result->val.quad_no = qno;
  result->type = e1.type;
  printf("924");

  SET_NOT_DEREF((*result));
  printf("927");

  printf("Leaving, %c", (char)op);
  // $$.type = MAX($1.type, $3.type);
}

void
make_two_quad (struct expr_type e1, int op) {
    // Store line number in quad table if needed
    char tname[10]; temp_var_name(next_quad, tname);    
        
    char *s1 = NULL;
    assign_name_to_buf(&s1, e1);

    fprintf(outfile, "%s = %c %s \n", tname, (char)op, s1);
    next_quad++;

    free(s1);
    return;
}

void
make_quad_by_name (char *e1, char *e2, int op) {
  char tname[10]; temp_var_name(next_quad++, tname);
  int i, idx = -1;
  printf("OP:%d\n", op);
  for (i = 0; i < BIGOPS_NUM; ++i) {
    if (bigops[i].op == op)
      idx = i;
  }
  printf("956\n");
  if (idx == -1) {
        printf("958\n");

    fprintf(outfile, "%s = %s %c %s\n", tname, e1, (char)op, e2);
  }
  else {
        printf("963\n");

    fprintf(outfile, "%s = %s %s %s\n", tname, e1, bigops[idx].str, e2);
  }
  printf("967\n");
  return;
}

void
make_quad_with_const (struct expr_type e, char *const_str, int op) {
  char *name = NULL; int mf;
  assign_name_to_buf(&name, e);
  make_quad_by_name(name, const_str, op);

  free(name);
}

void
make_quad (struct expr_type e1, struct expr_type e2, int op) {        
    char *s1 = NULL, *s2 = NULL;
    assign_name_to_buf(&s1, e1);
    assign_name_to_buf(&s2, e2);   
    printf("977\n");
    make_quad_by_name(s1, s2, op);
    printf("979\n");

    free(s1); free(s2);
    printf("982\n");

    return;
}

/* TODO: Change */
struct expr_type
out_member_ref (struct expr_type e, char *mem) {
  printf("1052\n");
  struct expr_type ret;
  if (e.type.ttype != COMPOUND_TYPE)
    error("request for member in something not a structure or union");
  printf("1056\n");

  int oft = struct_calc_offset(e.type.val.stype, mem);
  if (oft == -1)
    error("struct has no member named this");
  printf("1061\n");

  ret.type = struct_get_elem(e.type.val.stype, oft);
  printf("1064\n");

  ret.val.quad_no = next_quad;
  ret.ptr = QUAD_PTR;
  printf("1066\n");

  out_const_index(e, oft);
  printf("1069\n");

  return ret;
}

void
out_vector_offset (struct expr_type e, struct expr_type idx) {
  char *const_str; char *mname = NULL; 
  printf("1033\n");

  int oft_temp = next_quad;
  printf("1036\n");
  int sz_target;
  if (is_pointer(e.type)) {
    sz_target = size_of(*e.type.val.ptr_to);
  printf("1040\n");
  }

  else {
  printf("1043\n");

    struct array_type *t = &e.type.array;
    sz_target = (t->size/t->dimen[0]) * base_size_of(e.type);
  printf("1046\n");

  }
  int d = digits(sz_target);
  const_str = malloc(d * sizeof(int));
  printf("1052\n");

  snprintf(const_str, d, "%d", sz_target);
  assign_name_to_buf(&mname, idx);
  printf("1056\n");

  make_quad_by_name(mname, const_str, '*');

  free(mname);
  return;
}

void
out_index (struct expr_type e) {
  int oft_temp = next_quad, mf;
  char *name = NULL;
  out_vector_offset(e, *e.deref.idx);
  // error("Here");

  char tname[10], oft_name[10]; 
  assign_name_to_buf(&name, e);

  temp_var_name(next_quad++, tname);
  temp_var_name(oft_temp, oft_name);

  fprintf(outfile, "%s = %s [%s]\n", tname, name, oft_name);

  free(name);
}

void
out_const_index (struct expr_type e, const int c) {
  /* TODO: Take care of sizes (10 here) by allocating
   * global buffers maybe */
  char *name = NULL;
  assign_name_to_buf(&name, e);
  struct type *t = &e.type;
  int oft = (t->array.size / t->array.dimen[0]) * base_size_of(*t);
  // struct type redd = out_index(e, create_const_expr(const_str));
  fprintf(outfile, "_t%d = %s[%d]", next_quad++, name, c);

  free(name);
  return;
}

/* Called only for pointer dereferencing */
void
out_deref (struct expr_type e) {
  char *temp, *name = NULL;
  assign_name_to_buf(&name, e);
  temp = malloc(10 * sizeof(char));
  temp_var_name(next_quad++, temp);

  fprintf(outfile, "%s = * %s\n", temp, name);

  free(temp);  free(name);
}

/* Generated just above, for exmaple: int *p;
 * a = p[5] becomes _t0 = 5 * sizeof(*p);
 * _t1 = p + _t0; a = *_t1; */
void
out_deref_by_index (struct expr_type e) {
  struct expr_type final_ptr; 
  /* Get offset in bytes _t0 = 5 * sizeof(*p) */
  int oft_temp = next_quad;
  out_vector_offset(e, *e.deref.idx);

  /* Add offset to base address _t1 = p + _t0 */
  char oft[10]; char *base = NULL; 
  int final_addr = next_quad;
  assign_name_to_buf(&base, e);
  temp_var_name(oft_temp, oft);
  make_quad_by_name(base, oft, '+');

  /* Dereference the final address */
  final_ptr.type = e.type; 
  final_ptr.ptr = QUAD_PTR;
  final_ptr.val.quad_no = next_quad;
  final_ptr.deref = e.deref;

  out_deref(final_ptr);

  free(base);
}

/* e contains the details of the dereference */
struct expr_type
get_vector_elem (struct expr_type e) {
  struct expr_type ret;
  SET_NOT_DEREF(ret);
  ret.ptr = QUAD_PTR;
  ret.val.quad_no = next_quad; 
  if (is_array(e.type)) {
    if (is_derefd(e)) 
      out_const_index(e, 0);
    else {
      out_index(e);
      ret.val.quad_no++;
    }
    ret.type = arr_reduce_dimen(e.type);
  }
  else {
    /* expr is a pointer type */
    if (is_derefd(e))
      out_deref(e);
    else {
      ret.val.quad_no += 2;
      out_deref_by_index(e);
    }
    ret.type = *(e.type.val.ptr_to);
  }
  return ret;
}

void out_label () {
  char *ltext; 
  make_label_text(&ltext, label_no++);
  printf("In outlabel %d\n", label_no - 1);
  fprintf(outfile, "%s: ", ltext);
  free(ltext);
  printf("At end\n");
}


struct expr_type
compound_indexing (struct expr_type e, struct expr_type idx) {
  struct expr_type ret = e;
  int incr_size = e.type.array.size/e.type.array.dimen[0];
  char const_str[MAX_INT_SIZE];  snprintf(const_str, MAX_INT_SIZE, "%d", incr_size);

  make_quad_with_const(*(e.deref.idx), const_str, '*');
  int t = next_quad; char temp[20];
  temp_var_name(t, temp);
  make_quad_with_const(idx, temp, '+');

  ret.type = arr_reduce_dimen(ret.type);
  ret.deref.idx->ptr = QUAD_PTR;
  ret.deref.idx->val.quad_no = t;

  return ret;
}

struct expr_type
parse_indexed_expr (struct expr_type e, struct expr_type idx) {
  struct expr_type ret;
  if (is_indexed(e)) {
    if (e.type.array.n <= 1)
      error("subscripted value is neither array nor pointer nor vector");
    return compound_indexing(e, idx);
  }
  if (is_derefd(e))
    e = get_vector_elem(e);
  if (!is_array(e.type) && !is_pointer(e.type))
    error("subscripted value is neither array nor pointer nor vector");
  ret = e; ret.deref.type = INDEX_EXPR;
  ret.deref.idx = malloc(sizeof(struct expr_type));
  *(ret.deref.idx) = idx;

  return ret;
}

int 
sout_expr_with_deref (char *buf, struct expr_type e) {
  int t1 = next_quad; char *name = NULL;
  printf("1201\n");

  assign_name_to_buf(&name, e);
  if (is_derefd(e)) {
  printf("1205\n");

    return sprintf(buf, "*%s ", name);
  printf("1208\n");

  }
  else if (is_indexed(e)) {
  printf("1210, \n");

    out_vector_offset(e, *(e.deref.idx));
  printf("1215\n");

    return sprintf(buf, "%s[_t%d] ", name, t1);
  }
  else {
    printf("Name: %s\n", name);
    return sprintf(buf, "%s", name);
  }

}

void
out_assign_expr (struct expr_type lval, struct expr_type rval) {
  char *assign = malloc(2 * MAX_IDENTIFIER_SIZE * sizeof(char));
  int pos = 0;
  printf("1216\n");
  pos += sout_expr_with_deref(assign, lval);
  printf("1218\n");
  assign[pos++] = ' ';
  assign[pos++] = '='; assign[pos++] = ' ';
  pos += sout_expr_with_deref(assign + pos, rval);
  // assign[pos++] = '\n';
  assign[pos] = 0;
  printf("1223\n");

  fprintf(outfile, "OA: %s\n", assign);
  printf("1226\n");

  free(assign);
  printf("1229\n");

  return;
}

void
parse_assignment (struct expr_type lval, struct expr_type rval) {
  printf("1228\n");
  struct expr_type result; 
  if (is_void_type(rval.type))
    error("void value not ignored as it ought to be");
  printf("1232\n");

  if (!is_assignable(lval))
    error("error: lvalue required as left operand of assignment");
  if (is_equiv(lval.type, rval.type)) {
    printf("1237\n");

    out_assign_expr(lval, rval);
    return;
  }
  printf("1240\n");

  if (is_coercible(lval.type, rval.type)) {
    /* Warning goes here */
    out_assign_expr(lval, rval);
    return;
  } 
  printf("1247\n");

  
  /* Inconvertible, eg. incompatible types when assigning
   * to type 'float' from type 'int *' */
  error("Incompatible types for assignment");

}

void
out_begin_func () {
  fprintf(outfile, "FUNCTION BEGIN:\n");
}

void
out_end_func () {
  fprintf(outfile, "FUNCTION END\n\n\n");
}

void
out_return (struct expr_type *e) {
  if (!e) {
    if (!is_void_type(active_func->ret_type))
      warning("'return' with no value, in function returning non-void");
    fprintf(outfile, "return\n");
    return;
  }

  if (is_void_type(active_func->ret_type)) 
    warning("'return' with a value, in function returning void");

  else if (!is_equiv(e->type, active_func->ret_type)) {
    if (!is_coercible(e->type, active_func->ret_type))
      error("incompatible types when returning type");
  }

  char *name = NULL; assign_name_to_buf(&name, *e);
  fprintf(outfile, "return %s\n", name);

  free(name);
}


void
out_param (struct expr_type e) {
  char *name = NULL;
  assign_name_to_buf(&name, e);

  fprintf(outfile, "param %s\n", name);
  free(name);
}

void
out_call (struct func_rec *f) {
  if (!is_void_type(f->ret_type))
    fprintf(outfile, "param _result\n");
  fprintf(outfile, "call %s, %d\n", f->name, f->num_param);
  if (!is_void_type(f->ret_type))
    fprintf(outfile, "_t%d = _result\n", next_quad++);

  return;
}