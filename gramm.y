// Todo: Add coercibility checks
// Add string literals

%{
#include <math.h>  /* For math functions, cos(), sin(), etc. */
#include "calc.h"  /* Contains definition of `symrec'        */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define QUAD_PTR 0
#define SYM_PTR 2
#define CONST_PTR 1
#define MAX_NEST_DEPTH 256

#define JUMP_LABEL_NUMBER 0
#define JUMP_LABEL_NAME 1
#define JUMP_PATCH 2

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

struct expr_type 
create_const_expr(char *const_str);

%}

%union {
double  val;  /* For returning numbers.                   */  
char *id_name;
symrec *sym;
struct expr_type e;
int type;
int patch;
struct pair dual_patch;
struct loop_type loop;
}

%token OR_OP AND_OP EQ_OP NE_OP
%token LE_OP GE_OP LSHFT_OP RSHFT_OP INC_OP DEC_OP

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN
%token SIZEOF


%token <e> CONSTANT        /* Simple double precision number   */
%token <id_name> IDENTIFIER  /* Variable and Function            */

%type <patch> if_clause
%type <dual_patch> else_clause 
%type <loop> while_clause
%type <e> expr primary_expr opt_init function_call
%type <type> var_type var_dlist single_decl
%type <sym> symbol_name

// %precedence mult_op
// %precedence ad_op

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
%right INC_OP DEC_OP 
%right '!' '~'
%left UMINUS     /* Negation--unary minus */
%left ','

/* Grammar follows */

%%

// NEW
 

input :   /* empty */
      | input statement
;

statement     : declaration_statement {}
              | jump_statement {}
              | expression_statement {}
              | error { yyerrok; }
              | selection_statement {}
              | iterative_statement {}
        ;

expression_statement  :  expr ';'
                      |  /*empty*/  ';'
                      ;


jump_statement  : CONTINUE ';'
                  { 
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

declaration_statement  : var_type var_dlist ';' {
                $2 = $1; 
            }
          ;
          
var_dlist : single_decl ',' var_dlist { $1 = $$; }
          | single_decl { $1 = $$; }
          ;

single_decl : symbol_name opt_init {             
                $1->type = $$;                
                // If opt_init didn't go to EPS
                // generate the int. code for assingment
                if ($2.type != -1) {
                    printf("[%d]: %s\n", $1->type, $1->name);
                    out_assign($1->name, $2);
                }
              }
            ;

symbol_name : IDENTIFIER {
              // Create a new symbol table record
              // and assign it the thing from the old record   
              symrec *rec = getsym($1);
              if (rec) {
                // printf("Red of %s\n", $1);
                error("Redefinition of symbol");
              }
              rec = putsym($1, -1);
              $$ = rec;
            }              
          ;

var_type  : INT     { $$ = 1; }
          | FLOAT   { $$ = 2; }
          | CHAR    { $$ = 0; }
          ;

opt_init  :  '=' expr   { $$ = $2; }
          | /* empty */ { $$.type = -1; }
        ;

primary_expr  : CONSTANT  { 
                  int len = strlen($1.val.const_str);
                  char *temp = malloc((len + 1) * sizeof(char));
                  strcpy(temp, $1.val.const_str);
                  $$ = create_const_expr(temp);
                }
              | IDENTIFIER { 
                  symrec *rec = getsym($1);
                  if (!rec) {
                    error("Undefined symbol\n");
                  }
                  $$.ptr = SYM_PTR; $$.type = rec->type;
                  $$.val.sym = rec; 
                }
              | '(' expr ')' { $$ = $2; }
              | function_call
              ;

/* function call will be a standard expr type */
function_call : symbol_name '(' actual_params ')'
                {
                  // symrec becomes a union of 
                  // var_rec and func_rec
                  // actual parameters is a linked list of 
                  // expr

                  // Compare actual params with formal params
                  // to see if the types are coercible
                  // for each one that is, push it onto stack

                  // goto the label of the function record

                  // pop and call special form of gen_quad
                  // to store the value.

                  // finally, the value of function call
                  // becomes equal to the popped value
                  $$.type = $1.type; 
                }
              ;

actual_params : expr
              | actual_params ',' actual_params
              ;

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
expr    : primary_expr { $$ = $1; }
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
            if ($2.type != SYM_PTR) {
              error("lvalue required as increment operand");
            }
            out_assign($2.val.sym->name, $$);
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

void
main ()
{
  outfile = fopen("int.out", "w+");
  if (!outfile) {
    printf("Error opening output file\n");
    exit(1);
  }

  BIGOPS_NUM = sizeof(bigops);
  cur_loop.patch = cur_loop.label = -1;
  next_quad = 0;
  label_no = 1; patch_idx = 0;
  int i;
  for (i = 0; i< MAX_NEST_DEPTH; ++i)
    patches[i] = 0;

  init_table ();
  yyparse ();
}

yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s\n", s);
}

error (char *msg) {
  printf("%s\n", msg);
  exit(1);
}

struct init
{
  char *fname;
  double (*fnct)();
};

struct init arith_fncts[]
  = {
      "sin", sin,
      "cos", cos,
      "atan", atan,
      "ln", log,
      "exp", exp,
      "sqrt", sqrt,
      0, 0
    };

/* The symbol table: a chain of `struct symrec'.  */
symrec *sym_table = (symrec *)0;

void
init_table ()  /* puts arithmetic functions in table. */
{
  int i;
  symrec *ptr;
  // for (i = 0; arith_fncts[i].fname != 0; i++)
  //   {
  //     ptr = putsym (arith_fncts[i].fname, FNCT);
  //     ptr->value.fnctptr = arith_fncts[i].fnct;
  //   }
}

void
out_assign(char *name, struct expr_type expr) {
  char *s;
  int mf = assign_name_to_buf(&s, expr);

  fprintf(outfile, "%s = %s\n", name, s);

  if (mf) free(s);
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
    mf2 = assign_name_to_buf(&name, e);
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

void out_label () {
    char *ltext; 
    make_label_text(&ltext, label_no++);
    printf("In outlabel %d\n", label_no - 1);
    fprintf(outfile, "%s: ", ltext);
    free(ltext);
    printf("At end\n");
}


void
make_label_text (char **buf, int label) {
    *buf = malloc(101 * sizeof(char));
    snprintf(*buf, 100, "_L%d", label);    
}

void 
make_patch_text (char **buf, int patch) {
    *buf = malloc(10 * sizeof(char));
    snprintf(*buf, 10, "$%d     ", patch);  
}

int
get_const_type (char *const_str) {
  // check and return the type 
  // of the constane here
  return INT;
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

int
assign_name_to_buf(char **buf, struct expr_type e) {
  int mf = 0;
  if (e.ptr == CONST_PTR)
    *buf = e.val.const_str;
  else if (e.ptr == QUAD_PTR) {
    mf = 1;
    *buf = malloc(10 * sizeof(char));
    temp_var_name(e.val.quad_no, *buf);
  }
  else 
    *buf = (e.val.sym)->name;

  return mf;
}

void
temp_var_name(int idx, char *buf) {
  buf[0] = '_'; buf[1] = 't';
  snprintf(buf + 2, 7, "%d", idx);
}


struct expr_type 
create_const_expr(char *const_str) {
  struct expr_type e;
  e.type = get_const_type(const_str);
  e.ptr = CONST_PTR;
  e.val.const_str = const_str;

  return e;
}