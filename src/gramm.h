/* Basic types */
#define VOID_TYPE 0
#define CHAR_TYPE 1
#define INT_TYPE 2
#define FLOAT_TYPE 3
#define SHORT_TYPE 4
#define LONG_TYPE 5


#define QUAD_PTR 0
#define SYM_PTR 2
#define CONST_PTR 1
#define MAX_NEST_DEPTH 256
#define MAX_ARRAY_DIMEN 256

#define JUMP_LABEL_NUMBER 0
#define JUMP_LABEL_NAME 1
#define JUMP_PATCH 2

#define UNDEF_TYPE -1
#define INCOMPL_TYPE 0
#define COMPOUND_TYPE 2
#define BASIC_TYPE 1
#define PTR_TYPE 3

#define STRUCT_TAG 11
#define UNION_TAG 12

#define MAX_INT_SIZE 30
#define MAX_IDENTIFIER_SIZE 30
// #define CHAR 1
// #define INT 2
// #define FLOAT 3

#define SIZEOFPTR 4

#define is_struct(x) ((x).ttype == COMPOUND_TYPE)
#define is_array(x) ((x).array.n > 0)
#define is_pointer(x) ((x).ttype == PTR_TYPE)
#define is_int_type(t) ((t).ttype == BASIC_TYPE && ((t).val.btype == INT_TYPE || (t).val.btype == CHAR_TYPE))
#define is_void_type(t) ((t).ttype == BASIC_TYPE && (t).val.btype == VOID_TYPE)
#define is_int_expr(e) (is_int_type(e.type))


#define SET_NOT_ARRAY(x) x.array.n = 0; x.array.dimen = NULL; x.array.size = 1

extern int nlabel;
extern int depth;

int lineno;
int colno;

void out_label();
int out_jmp(struct expr_type *e, void *label, int type);
void backpatch(int label, int patch);
void out_assign(char *name, struct expr_type expr);
void out_index (struct expr_type e);
struct expr_type out_member_ref (struct expr_type e, char *mem);
void parse_expr (struct expr_type *result, struct expr_type e1,
          struct expr_type e2, int op);
void parse_unary_expr (struct expr_type *result, 
              struct expr_type e1, int op);
void out_deref (struct expr_type e);
void out_const_index (struct expr_type e, const int c);

void make_quad (struct expr_type e1, struct expr_type e2, int op);
void make_two_quad (struct expr_type e1, int op);

void out_gen_quad (struct expr_type e);

struct expr_type get_vector_elem (struct expr_type e);
struct expr_type compound_indexing (struct expr_type e, struct expr_type idx);
struct expr_type parse_indexed_expr (struct expr_type e, struct expr_type idx);
int sout_expr_with_deref (char *buf, struct expr_type e);
void out_assign_expr (struct expr_type lval, struct expr_type rval);
void parse_assignment (struct expr_type lval, struct expr_type rval);

void out_begin_func ();
void out_end_func ();
void out_return (struct expr_type *e);
void out_param (struct expr_type e);
void out_call (struct func_rec *f);

void error (char *msg);
