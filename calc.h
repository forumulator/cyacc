#include <stdbool.h>
#include "list.h"

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
/* An alternate way to do this, and probably the way gcc does it,
 * is to store pointers to more type structs even in case of 
 * arrays, and in that case every of these structs will have 
 * at max a 1-D array, which will be an array of pointers
 * to further array type. So, in int *a[5][6][7]; we store one 
 * type struct with a array 5 of pointers to int [6][7], i.e the
 * first struct element corresponds to 5 int * (*)[6][7] pointers, the 
 * second to 6 int * (*)[7] pointers(i.e pointers to [7] array of
 * int *, and the third to int * (*) or pointer to int *, and so on.
 */ 

/* Also, arrays usually decay to pointers to their
  first element type */
/* TODO: Change the list implementation from "list.c"
 * to suit the usage here, and use that everywhere */
struct array_type{
    int n;
    int size;
    int *dimen;
}; 

struct type {
  // Indicates basic types
  int ttype;
  union {
    int btype;
    struct struct_type *stype;
    /* THis has to be changed to the standard list */
    struct type *ptr_to;
  } val;
  struct array_type array;
};

struct memb_list {
  char *name;
  struct type typerec;
  struct memb_list *next;
};

/* type of compound type mem here
i.e STRUCT vs. UNION vs. enum and so on */
struct struct_type {
  char *name;
  int size;
  struct memb_list *elems;
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

struct struct_type *create_struct(char *name, struct memb_list* elems);
struct struct_type *get_struct(char *name);
void init_tables();

struct alias_rec *get_alias(char *name);
struct alias_rec *create_alias(char *name, struct type type);
