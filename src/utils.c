#include "utils.h"
#include "func.h"
#include "gramm.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
  int type;
  union {
    int i; float f;
  } val;
} b10_val;

/* Takes only positive const strings and returns a value */
b10_val hex_val (char *str) {
  int ipart = 0; int type = INT_TYPE;
  b10_val ret; ret.type = UNDEF_TYPE;
  int last; float fpart = 0;
  if (!str)
    return ret;
  if (!(str[0] == '0' && str[1] == 'x'))
    return ret;

  int i; 
  for (i = 0; str[i] && str[i] != '.'; i++) {
    ipart = (ipart * 16) + (str[i] - '0');
  }

  if (str[i] == '.') {
    last = strlen(str) - 1;
    type = FLOAT_TYPE;
    for (i = last; str[i] != '.'; --i)
      fpart = (fpart + (str[i] - '0') ) / 16;
  }
  ret.type = type;
  if (type == FLOAT_TYPE)
    ret.val.f = ipart + fpart;
  else
    ret.val.i = ipart;

  return ret;
}

/* TODO: Also add pointer deref. here */
struct type
arr_reduce_dimen (struct type t) {
  struct type ret;
  if (!is_array(t)) {
    ret.ttype = UNDEF_TYPE;
    return ret;
  }
  ret = t;
  // Arrays are copied by value here.
  ret.array.dimen = malloc((t.array.n - 1) * sizeof(int));
  ret.array.size /= t.array.dimen[0];

  int i;
  for (i = 1; i < t.array.n; ++i)
    ret.array.dimen[i - 1] = t.array.dimen[i];
  ret.array.n = t.array.n - 1;
  return ret;
}

struct type
pointer_deref (struct type t) {
  struct type ret;
  ret.ttype = UNDEF_TYPE;
  if (is_array(t))
    return arr_reduce_dimen(t);
  else if (!is_pointer(t))
    return ret;

  return *(t.val.ptr_to);
}

struct expr_type 
create_const_expr (char *const_str) {
  struct expr_type e; e.type.ttype = UNDEF_TYPE;
  if (!const_str)
    return e;
  e.type.ttype = BASIC_TYPE;
  e.type.val.btype = const_type(const_str);
  SET_NOT_ARRAY(e.type);
  e.ptr = CONST_PTR;
  e.val.const_str = const_str;
  SET_NOT_DEREF(e);
  return e;
}

struct expr_type 
create_const_expr2 (const int c) {
  struct expr_type e; e.type.ttype = UNDEF_TYPE;
  int size = digits(c) + 1;
  char *const_str = malloc(size * sizeof(char));
  snprintf(const_str, size, "%d", c);
  
  e.type = basic_types[INT_TYPE].t;

  e.ptr = CONST_PTR;
  e.val.const_str = const_str;
  SET_NOT_DEREF(e);
  return e;
}

struct expr_type
create_temp_expr (int temp, struct type t) {
  struct expr_type e;
  e.ptr = QUAD_PTR;
  e.val.quad_no = temp;
  e.type = t;
  SET_NOT_DEREF(e);

  return e;
}

struct expr_type
create_sym_expr (symrec *sym) {
  struct expr_type ret; 
  ret.type.ttype = UNDEF_TYPE;
  if (!sym)
    return ret;
  SET_NOT_ARRAY(ret.type);
  ret.ptr = SYM_PTR; 
  ret.type = sym->type;  // Think about it: redundancy, how to eliminate
  ret.val.sym = sym;
  SET_NOT_DEREF(ret);
  return ret; 
}

int
const_type (char *const_str) {
  /* TODO: Maybe set the type
  * from the lexer itself */
  if (const_str[0] == '\'' && const_str[2] == '\'' && !const_str[3])
    return CHAR_TYPE;
  int i = 0;
  while (const_str[i]) {
    if (const_str[i] == '.')
      return FLOAT_TYPE;
    i++;
  }
  return INT_TYPE;
}

int 
const_val (char *const_str) {
  if (const_type(const_str) == CHAR_TYPE)
    return const_str[1];
  // Add hex and octal support
  // Also stirng literals
  return atoi(const_str);
}

int
is_coercible (struct type to, struct type from) {
  if (to.ttype == COMPOUND_TYPE || from.ttype == COMPOUND_TYPE)
      return 0;
  if (is_int_type(to) || is_int_type(from)) {
    if (size_of(to) != size_of(from))
      // With warning
      return 2;
    return 1;
  }
  if (is_vector(to) && is_vector(from))
      return 1;
  return (is_equiv(to, from));
}

int
is_lval_type (struct type t) {
  if (is_array(t))
    return 0;  
  return 1;
}

void
array_decay (struct expr_type *e) {
  if (!is_array(e->type))
    return;
  struct type *t = malloc(sizeof(struct type));
  *t = e->type;
  e->type.ttype = PTR_TYPE;
  e->type.val.ptr_to = t;
  SET_NOT_ARRAY(e->type);
  SET_NOT_ARRAY(*t);
  return;
}

/* expressions are assignable only if they are an
 * indexing or deref or a symbol */
int
is_assignable (struct expr_type e) {
  struct type t = e.type;
  /* An array or pointer dereference 
   * is a memory address, thus always
   * assignable */
  if (is_indexed(e) || is_derefd(e)) {
    return is_lval_type(t);
  }
  
  /* Is this a symbol table entry */
  if (e.ptr == SYM_PTR) {
    return is_lval_type(t);
  }
  /* Otherwise not assignable, for 
   * constants and other exprs */
  return 0;
}

void 
copy_name (char **buf, char *name) {
  if (!name)
    return;
  *buf = malloc((strlen(name)  + 1)* sizeof(char));
  strcpy(*buf, name);
  return;
}

int 
is_equiv(struct type t1, struct type t2) {
  int eq_flag = 1;
  if (is_vector(t1) != is_vector(t2))
    return 0;
  if (t1.ttype == UNDEF_TYPE || t2.ttype == UNDEF_TYPE)
    return 0;
  if (t1.ttype != t2.ttype)
    return 0;
  // Check the dimensions too
  if (t1.array.n != t2.array.n)
    return 0;
  if (t1.ttype == PTR_TYPE) {
    return is_equiv(*t1.val.ptr_to, *t2.val.ptr_to);
  }
  else if (t1.ttype == COMPOUND_TYPE) {
    return (t1.val.stype == t2.val.stype);
  }
  else return (t1.val.btype == t2.val.btype);

}

int
is_incompl_type (struct type t) {
  if (t.ttype == INCOMPL_TYPE ||
      t.ttype == UNDEF_TYPE)
    return 1;
  if (t.ttype == COMPOUND_TYPE && 
      t.val.stype->size == -1)
    return 1;
  return 0;
}


void 
list_join (struct list **l, struct list **m) {
    if (!*l) {
        *l = *m;
        return;
    }
    struct list *node = *l;
    while (node->next) 
        node = node->next;

    node->next = *m;
    return;
}

void 
list_append_elem (struct list **l, struct list *elem) {
    if (!l)
        return;

    if (!*l) {
        *l = elem;
        return;
    }
    struct list *node = *l;
    while (node->next)
        node = node->next;
    node->next = elem;
    return;
}

void 
list_prepend_elem (struct list **l, struct list *elem) {
    if (!l)
        return;
    elem->next = *l;
    *l = elem;
    return;
}

struct list *
list_create_elem (void *data) {
    struct list *newnode = malloc(sizeof(struct list));
    newnode->data = data;
    newnode->next = NULL;

    return newnode;
}

void *
list_pop_front (struct list **l) {
    if (!l || !*l)
        return NULL;
    struct list *elem = *l;
    *l = elem->next;
    void *data = elem->data;
    free(elem);
    return data;
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

/* Ugly stuff, but basically if we pass a pointer to
 * a NULL ptr, then we assign a buffer, else assume the 
 * buffer is already assigned, the (int **) is cast 
 * to (int *) */
int
assign_name_to_buf(char **buf, struct expr_type e) {
  int mf = 0; int pos = 0; char *name;

  if (!*buf) {
    // printf("NOT *buf");
    *buf = malloc(MAX_IDENTIFIER_SIZE * sizeof(char));
    name = *buf;
  }
  else 
    name = (int *)buf;
  // if (is_derefd(e))
  //   name[pos++] = '*';

  if (e.ptr == CONST_PTR) {
    pos += cstrcpy(name + pos, e.val.const_str) - 1;
  }
  else if (e.ptr == QUAD_PTR) {
    mf = 1;
    temp_var_name(e.val.quad_no, name + pos);
    pos += digits(e.val.quad_no) + 1;
  }
  else {
    pos += cstrcpy(name + pos, (e.val.sym)->name) - 1;
  }

  /* if e is indexed, then this will be a[idx] */
  // if (is_indexed(e)) {
  //   name[pos++] = '[';
  //   name[pos] = 1;
  //   pos += assign_name_to_buf((int **)(name + pos), *e.array.idx);
  //   name[pos++] = ']';
  // }
  name[pos + 1] = '\0';
  return pos;
}

struct type
get_target_type (struct expr_type e) {
  if (is_indexed(e)) {
    if (is_array(e.type)) {
      return arr_reduce_dimen(e.type);
    }
    else {
      /* Structures member access */
      return struct_get_elem(e.type.val.stype, e.deref.mem_oft);
    }
  }
  else if (is_derefd(e)) {
    return *(e.type.val.ptr_to);
  } 
  else
    return e.type;
}


void
temp_var_name(int idx, char *buf) {
  if (!buf)
    return;
  buf[0] = '_'; buf[1] = 't';
  snprintf(buf + 2, 7, "%d", idx);
}

/* Actually returns d + 1 for d digits */
int 
digits (int num) {
  int d = 1;
  while (num) {
    num = num / 10;
    d++;
  } 
  return d;
}

int
cstrcpy (char *dest, char *src) {
  if (!src || !dest)
    return 0;
  int nchars = 0;
  while (*dest++ = *src++)
    nchars++;
  *dest = 0;
  return nchars + 1;
}

char *citostr (const int c) {
  int d = digits(c);
  char *str = malloc(d * sizeof(char));
  snprintf(str, d, "%d", c);
  return str;
}

// char *cftostr (const float f) {
//   int d = digits(c);
//   char *str = malloc(d * sizeof(char));
//   snprintf(str, d, "%d", c);
//   return str;
// }

void print_type(struct type t) {
  struct type *p = &t;
  while (p) {
    if (p->ttype == BASIC_TYPE)
      printf("(B_T, %d, %d) -> ", p->val.btype, is_array(*p));
    else if (p->ttype == COMPOUND_TYPE)
      printf("(C_T, %s, %d) -> ", p->val.stype->name, is_array(*p));
    else
      printf("(P_T, %d) -> ", is_array(*p));

    if (p->ttype == PTR_TYPE)
      p = p->val.ptr_to;
    else
      p = NULL;
  }
}

void fprint_type(FILE *tfile, struct type t) {
  struct type *p = &t;
  while (p) {
    if (p->ttype == BASIC_TYPE)
      fprintf(tfile, "(B_T, %d, %d) -> ", p->val.btype, is_array(*p));
    else if (p->ttype == COMPOUND_TYPE)
      fprintf(tfile, "(C_T, %s, %d) -> ", p->val.stype->name, is_array(*p));
    else
      fprintf(tfile, "(P_T, %d) -> ", is_array(*p));

    if (p->ttype == PTR_TYPE)
      p = p->val.ptr_to;
    else
      p = NULL;
  }
}


void dump_tables() {
  dump_sym_tables();
  // dump_struct_table();
  // dump_alias_table();
}

void dump_sym_tables() {
  const char *DUMP_FILE = "sym_tables.txt";
  printf("DUMPING all funcitons\n");
  FILE *tfile = fopen(DUMP_FILE, "w");
  if (!tfile) {
    printf("Unable to open file %s", DUMP_FILE);
    return;
  }
  struct list *node;
  for (node = func_table; node; node = node->next) {
    struct func_rec *func = (struct func_rec *)node->data;
    printf("DUMPING@@@@\n");
    fprintf(tfile, "================ FUNCTION: %s, LABEL:%d, RET_TYPE: ", func->name, func->label);
    fprint_type(tfile, func->ret_type);
    fprintf(tfile, "\n" );
    dump_table (tfile, func->sym_table);
    fprintf(tfile, "\n\n");
  }
}


void dump_table (FILE *tfile, struct list *sym_table) {
  symrec *sym;
  struct list *node; 
  for (node = sym_table; node; node = node->next) {
    sym = (symrec *)node->data;
    fprintf(tfile, "%s, %d, %d:, ", sym->name, sym->scope.level, sym->scope.label);
    fprint_type(tfile, sym->type);
    fprintf(tfile, "\n");
  }
}