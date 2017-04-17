#include <stdbool.h>

/* Data type for links in the chain of symbols.      */
struct symrec
{
  char *name;  /* name of symbol                     */
  // int rec_type = VAR_REC , or FUNC_REC
  int type;    /* type of symbol: either VAR or FNCT */
  union {
    struct var_rec var;           /* value of a VAR          */
    struct func_rec func;  /* value of a FNCT         */
  } value;
  bool param;
  struct symrec *next;    /* link field              */
};

typedef struct symrec symrec;

struct var_rec{
  // containes scoping and other info
};

struct func_rec {
  int addr;
  int *formal;
};

union expr_val {
  char *const_str;
  int quad_no;
  symrec *sym;
};

struct pair {
  int patch;
  int label;
};

struct loop_type {
  struct pair this;
  struct pair prev;
};



struct expr_type {
  int ptr;
  union expr_val val;
  int type;
};

struct quad {
  int line;
};



/* The symbol table: a chain of `struct symrec'.     */
extern symrec *sym_table;

symrec *putsym ();
symrec *getsym ();


