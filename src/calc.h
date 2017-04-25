#include <stdbool.h>
// #include "list.h"

#define _CALC

#define NOT_DEREF 0
#define INDEX_EXPR 2
#define DEREF_EXPR 1

#define SET_NOT_DEREF(x) (x).deref.type = NOT_DEREF ; (x).deref.idx = NULL
#define is_indexed(x) ((x).deref.type == INDEX_EXPR)
#define is_derefd(x) ((x).deref.type == DEREF_EXPR)

#define is_compound(x) ((x).ttype == COMPOUND_TYPE)
#define is_vector(x) (is_array(x) || is_pointer(x))
#define is_array(x) ((x).array.n > 0)
#define is_pointer(x) ((x).ttype == PTR_TYPE)

#define is_int_type(t) ((t).ttype == BASIC_TYPE && ((t).val.btype == INT_TYPE || (t).val.btype == CHAR_TYPE) && !is_array(t))
#define is_void_type(t) ((t).ttype == BASIC_TYPE && (t).val.btype == VOID_TYPE)
#define is_int_expr(e) (is_int_type(e.type))

#define is_plus(op) (op == '+' || op == '-')
#define is_relational(op) (op == '>' || op == '<' || op == LE_OP || op == GE_OP || op == EQ_OP)
#define is_logical(op) (op == AND_OP || op == OR_OP)
#define is_binary(op) (op == '&' || op == '|' || op == '^')

struct scope_type {
  int level;
  int label;
  int over; // is the scope of this var over
};

struct struct_type;

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


struct btype_info{
  char *name;
  int size;
  struct type t;
};

/* Data type for links in the chain of symbols.      */
struct symrec
{
  char *name;  /* name of symbol                     */
  struct type type;
  bool param;
  struct scope_type scope;
};

typedef struct symrec symrec;

struct alias_rec {
  char *name;
  struct type to;
};

struct memb_list {
  char *name;
  struct type type;
  struct memb_list *next;
};

/* type of compound type mem here
i.e STRUCT vs. UNION vs. enum and so on */
struct struct_type {
  char *name;
  int size;
  struct memb_list *elems;
} ;

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

struct deref_info {
  int type;
  struct expr_type *idx; /* Stores expression for the index of [idx] */
  int mem_oft; /* Stores member offset for struct member access */
};

struct expr_type {
  int ptr;
  union expr_val val;
  struct type type;
  /* Stores info of dereference for 
   * indexing and ptr deref expr */
  struct deref_info deref; 
};


struct quad {
  int line;
};


/* The symbol table: a chain of `struct symrec'.     */
/* TODO: Change Symtable to struct list * */
extern struct list *global_sym_table;
// Alias table, list of `struct alias_rec'
extern struct list *aliases;
// Struct and Unions table, list of `struct struct_type'
extern struct list *cmpnd_types;
extern struct btype_info basic_types[];


void delsym_scope(int depth);

struct struct_type *create_struct(char *name, struct memb_list* elems, int incompl);
struct struct_type *get_struct(char *name);
struct type struct_get_elem (struct struct_type *stype, int oft);
int struct_calc_offset (struct struct_type *stype, char *name);
void init_tables();

struct type *get_alias(char *name);
void create_alias(char *name, struct type type);

struct memb_list *create_member (char *name, struct memb_list *join);

int size_of_target(struct type t);

int size_of (struct type t);
int base_size_of (struct type t);