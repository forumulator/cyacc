#include <stdbool.h>

struct scope_type {
  int level;
  int label;
  int over; // is the scope of this var over
};
/* Data type for links in the chain of symbols.      */
struct symrec
{
  char *name;  /* name of symbol                     */
  struct type type;
  bool param;
  struct symrec *next;    /* link field              */
  struct scope_type scope;
};

typedef struct symrec symrec;

struct alias_rec {
  char *name;
  struct type to;
};

// `struct type` is passed around by value,
// not pointers.
struct type {
  // Indicates basic types
  int ttype;
  union {
    int btype;
    struct struct_type *stype;
  } val;
};

struct type_list {
  char *name;
  struct type typerec;
  struct type_list *next;
};

/* type of compound type mem here
i.e STRUCT vs. UNION vs. enum and so on */
struct struct_type {
  char *name;
  int size;
  struct type_list *elems;
} ;

struct func_rec {
  int addr;
  int *formal;
};

struct pair {
  int patch;
  int label;
};

struct loop_type {
  struct pair this;
  struct pair prev;
};

union expr_val {
  char *const_str;
  int quad_no;
  symrec *sym;
};

struct expr_type {
  int ptr;
  union expr_val val;
  struct type type;
};

struct quad {
  int line;
};



extern int depth, nabel;
/* The symbol table: a chain of `struct symrec'.     */
extern struct list *sym_table;
// Alias table, list of `struct alias_rec'
extern struct list *aliases;
// Struct and Unions table, list of `struct struct_type'
extern struct list *cmpnd_types;

symrec *putsym ();
symrec *getsym ();
void delsym_scope(int depth);

struct struct_type *create_struct(char *name, struct type_list* elems);
struct struct_type *get_struct(char *name);
void init_tables();

struct alias_rec *get_alias(char *name);
struct alias_rec *create_alias(char *name, struct type type);
