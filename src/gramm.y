// Todo: Add coercibility checks
// Add string literals

/* TODO: SET INDICES and #defines PROPERLY */

%{
#include <math.h>  /* For math functions, cos(), sin(), etc. */
// #include "calc.h"  /* Contains definition of `symrec'        */
#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
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

// Builtin type info.
void init_gloabals();

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
%token <id_name> IDENTIFIER  /* Variable and Function            */
%token <alias_type> ALIAS_NAME;

%type <patch> if_clause
%type <dual_patch> else_clause 
%type <loop> while_clause
%type <e> expr primary_expr opt_init // function_call
%type <type> type_name compound_type
%type <l> var_dlist var_definition
%type <sym_npt> symbol_name
%type <ttype> type_type
%type <t_name> opt_typ_name;
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
      | input statement
      ;


statement     : declaration_statement {}
              | jump_statement {}
              | expression_statement {}
              | error { yyerrok; }
              | selection_statement {}
              | iterative_statement {}
              | block_statement {}
              | label_stmt {}
              | type_definition
        ;

// User defined label
label_stmt: IDENTIFIER ':' { fprintf(outfile, "%s: ", $1); }
          ;

/* TODO: Differentiate between stmts inside 
and outside functions */
block_statement : begin_sub '{' input '}' end_sub
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
                list_pop_front(&nested);
                scope.label = (int) nested->data;
                delsym_scope(scope.level);
                scope.level--;
              }
          ;

type_definition : aliasing ';'
                | compound_type ';'
                ;

// Forward declarations of structs ignored for now
/* TODO: Allow definitions of recursive structs pointers by 
 * combining the two */
/* TODO: Check for duplicate members */
compound_type   : type_type opt_typ_name '{' member_decl_list '}'
                    { 
                      printf("nam1e %s\n", $2);
                      if (get_struct($2))
                        error("Redefinition of struct");
                      /* TODO: Differentiate b/w STRUCT and
                       * UNION */
                      $$.val.stype = create_struct($2, $4, false);
                      $$.ttype = COMPOUND_TYPE;
                      SET_NOT_ARRAY($$);
                    }
                | type_type IDENTIFIER
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
                  }
                ;

type_type : STRUCT { $$ = STRUCT_TAG; } 
          | UNION  { $$ = UNION_TAG; }
          ;

opt_typ_name: /* empty */ { $$ = ""; }
            | IDENTIFIER  { copy_name(&$$, $1); }
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

while_loop          : while_clause statement
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

selection_statement  :  if_clause statement {
                          int l_no = label_no;
                          out_label();
                          backpatch(l_no, $1); 
                        }
                     | if_clause statement else_clause statement
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
          
var_dlist : var_definition ',' var_dlist { list_prepend_elem(&$3, $1); $$ = $3; }
          | var_definition { $$ = $1; }
          ;


var_definition  : symbol_name opt_init 
                  {
                    symrec *rec = getsym($1.name, scope);
                    if (rec) {
                      error("Redefinition of symbol");
                    }
                    rec = putsym($1.name, $1.type, scope);
                    $$ = list_create_elem(rec);            
                    
                    // Assign result of expr to vaiable
                    // This is should be delayed to after the 
                    // type backpatch to check coercibility
                    if ($2.type.ttype != UNDEF_TYPE) {
                        out_assign($1.name, $2);
                    }
                    free($1.name);
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
                else
                  t->array.n++;
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
type_name : INT    
            { 
              $$.ttype = BASIC_TYPE;
              $$.val.btype = INT_TYPE;
            }
          | FLOAT
            { 
              $$.ttype = BASIC_TYPE;
              $$.val.btype = FLOAT_TYPE;
            }
          | CHAR
            { 
              $$.ttype = BASIC_TYPE;
              $$.val.btype = CHAR_TYPE;
            }
          | compound_type { $$ = $1; }
          | ALIAS_NAME { $$ = *$1; }
          ;

opt_init  :  '=' expr   { $$ = $2; }
          | /* empty */ { $$.type.ttype = UNDEF_TYPE; }
        ;

/* TODO: array initializers, struct initializers */
primary_expr  : CONSTANT  { 
                  char *temp;
                  copy_name(&temp, $1.val.const_str);
                  $$ = create_const_expr(temp);
                }
              | IDENTIFIER { 
                  symrec *rec = getsym($1);
                  if (!rec) {
                    error("Undefined symbol\n");
                  }
                  $$ = create_sym_expr(rec);
                }
              | '(' expr ')' { $$ = $2; }
              // | function_call
              ;

// /* function call will be a standard expr type */
// function_call : symbol_name '(' actual_params ')'
//                 {
//                   // symrec becomes a union of 
//                   // var_rec and func_rec
//                   // actual parameters is a linked list of 
//                   // expr

//                   // Compare actual params with formal params
//                   // to see if the types are coercible
//                   // for each one that is, push it onto stack

//                   // goto the label of the function record

//                   // pop and call special form of gen_quad
//                   // to store the value.

//                   // finally, the value of function call
//                   // becomes equal to the popped value
//                   $$.type = $1.type; 
//                 }
//               ;

// actual_params : expr
//               | actual_params ',' actual_params
//               ;

// %right '='
// %left OR_OP
// %left AND_OP
// %left '&' 
// %left '^'
// %left '|'
// %left EQ_OP NE_OP
// %left '<' '>' LE_OP GE_OP
// %left LSHFT_OP RSHFT_OP
// %left '-' '+'
// %left '*' '/' '%'
// %right INC_OP DEC_OP 
// %right '!' '~'

// Note that basic types can be inconverted , but compound types can't
// i.e struct test t; int b = (int)t; is an error
expr    : primary_expr { $$ = $1; }
        | expr indexing
          {
              /* TODO: Add the check for pointer here */
            if (!is_array($1.type) || !is_pointer($1.type))
              error("subscripted value is neither array nor pointer nor vector");
            $$.val.quad_no = next_quad;
            $$.ptr = QUAD_PTR;
            $$.type = arr_reduce_dimen($1.type);
            out_index($1, $2);

          }
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
            if (!is_array($2.type) || !is_pointer($2.type))
              error("Attempting to dereference non-pointer");
            $$.val.quad_no = next_quad;
            $$.ptr = QUAD_PTR;
            $$.type = pointer_deref($2.type);
            out_deref($2);
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
        | primary_expr '=' expr  { 
            if ($1.ptr != SYM_PTR) {
              error("Assignment should have an assignable on the left");
            }
            out_assign($1.val.sym->name, $3);
          }
        ;

indexing  : '[' expr ']'
            {
              $$ = $2;
              if (!is_int_expr($2)) // or convertible to int
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
main (int argc, char **argv)
{
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
}

yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s\n", s);
}

void
error (char *msg) {
  printf("%s\n", msg);
  exit(1);
}

struct init
{
  char *fname;
  double (*fnct)();
};


void
out_assign(char *name, struct expr_type expr) {
  char *s;
  int mf = assign_name_to_buf(&s, expr);

  fprintf(outfile, "%s = %s\n", name, s);

  if (mf) free(s);
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
  char *ltext, *cond, *name; int i = -1;
  int mf1 = 0, mf2 = 0;
  if (!label) {
    // 5 spaces, temporarily so that label name can be accomodated
    mf1 = 1;
    i = 0;
    while(i < MAX_NEST_DEPTH && i < patches[i])
      i++;

    if (i == MAX_NEST_DEPTH)
      error("Can't nest more than 256 levels");

    make_patch_text(&ltext, i);
    patches[i] = 1;
  }
  else {
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

    }
  }

  if (e) {
    cond = malloc(100 * sizeof(char));
    mf2 = assign_name_to_buf(&name, *e);
    printf("Befor cond print\n");
    snprintf(cond, 100, "if ( %s == 0 )\n", name);
    printf(cond);
  }
  else 
    cond = "";

  fprintf(outfile, "%s goto %s\n", cond, ltext);

  if (mf1)  free(ltext);
  if (e) free(cond);
  if (mf2) free(name);

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
    // Check for coercibility here
    int qno = next_quad;
    make_two_quad(e1, op);
    result->ptr = QUAD_PTR; result->val.quad_no = qno;
    // $$.type = MAX($1.type, $3.type);
}


void
parse_expr (struct expr_type *result, struct expr_type e1,
          struct expr_type e2, int op) {
    // Check for coercibility here
    int qno = next_quad;
    make_quad(e1, e2, op);
    result->ptr = QUAD_PTR; result->val.quad_no = qno;
    // $$.type = MAX($1.type, $3.type);
}

void
make_two_quad (struct expr_type e1, int op) {
    // Store line number in quad table if needed
    char tname[10]; temp_var_name(next_quad, tname);    
        
    char *s1; int mf1 = 0;
    mf1 = assign_name_to_buf(&s1, e1);

    fprintf(outfile, "%s = %c %s \n", tname, (char)op, s1);
    next_quad++;

    if (mf1) free(s1);
    return;
}

void
make_quad (struct expr_type e1, struct expr_type e2, int op) {
    // Store line number in quad table if needed
    char tname[10]; temp_var_name(next_quad, tname);   
    int idx = -1, i;
    for (i = 0; i < BIGOPS_NUM; ++i) {
      if (bigops[i].op == op)
        idx = i;
    }     
        
    char *s1, *s2; int mf1 = 0, mf2 = 0;
    mf1 = assign_name_to_buf(&s1, e1);
    mf1 = assign_name_to_buf(&s2, e2);   

    if (idx == -1)
      fprintf(outfile, "%s = %s %c %s\n", tname, s1, (char)op, s2);
    else
      fprintf(outfile, "%s = %s %s %s\n", tname, s1, bigops[idx].str, s2);

    next_quad++;

    if (mf1) free(s1);
    if (mf2) free(s2);

    return;
}


struct expr_type
out_member_ref (struct expr_type e, char *mem) {
  struct expr_type ret;
  if (e.type.ttype != COMPOUND_TYPE)
    error("request for member in something not a structure or union");
  int oft = struct_calc_offset(e.type.val.stype, mem);
  if (oft == -1)
    error("struct has no member named this");
  ret.type = struct_get_elem(e.type.val.stype, oft);
  ret.val.quad_no = next_quad;
  ret.ptr = QUAD_PTR;

  out_const_index(e, oft);
  return ret;
}

void
out_index (struct expr_type e, struct expr_type idx) {
  char *name, *iname, tname[10]; int mf, imf;
  imf = assign_name_to_buf(&iname, idx);
  mf = assign_name_to_buf(&name, e);
  temp_var_name(next_quad++, tname);
  fprintf(outfile, "%s = %s [%s]\n", tname, name, iname);

  if (mf) free(name);
  if (imf) free(iname);
}

void 
out_const_index (struct expr_type e, const int c) {
  /* TODO: Take care of sizes (10 here) by allocating
   * global buffers maybe */
  char *const_str = malloc(10 * sizeof(int));
  snprintf(const_str, 10, "%d", c);
  out_index(e, create_const_expr(const_str));
  free(const_str);
}

void 
out_deref (struct expr_type e) {
  if (is_array(e.type))
    out_const_index(e, 0); // Index at offset 0
  char *temp, *name; int mf;
  mf = assign_name_to_buf(&name, e);
  temp = malloc(10 * sizeof(char));
  temp_var_name(next_quad++, temp);

  fprintf(outfile, "%s = * %s\n", temp, name);
  free(temp);
  if (mf) free(name);
}

void out_label () {
  char *ltext; 
  make_label_text(&ltext, label_no++);
  printf("In outlabel %d\n", label_no - 1);
  fprintf(outfile, "%s: ", ltext);
  free(ltext);
  printf("At end\n");
}