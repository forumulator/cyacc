#include "utils.h"
#include "func.h"
#include "gramm.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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
    return INT_TYPE;
}

int 
const_val (char *const_str) {
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
  if (to.ttype == PTR_TYPE && from.ttype == PTR_TYPE)
      return 1;
  return (is_equiv(to, from));
}

/* expressions are assignable only if they are an
 * indexing or deref or a symbol */
int
is_assignable (struct expr_type e) {
  /* Is this a symbol table entry */
  if (e.ptr == SYM_PTR)
    return true;
  if (is_indexed(e) || is_derefd(e))
    return true;
  return false;
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
    printf("NOT *buf");
    *buf = malloc(MAX_IDENTIFIER_SIZE * sizeof(char));
    name = *buf;
  }
  else 
    name = (int *)buf;

  printf("238\n");

  
  // if (is_derefd(e))
  //   name[pos++] = '*';

  if (e.ptr == CONST_PTR) {
    printf("245\n");
    pos += cstrcpy(name + pos, e.val.const_str) - 1;
    printf("245\n");
  }
  else if (e.ptr == QUAD_PTR) {
    printf("249\n");
    mf = 1;
    temp_var_name(e.val.quad_no, name + pos);
    pos += digits(e.val.quad_no) + 1;
    printf("253\n");
  }
  else {
    printf("255\n");
    pos += cstrcpy(name + pos, (e.val.sym)->name) - 1;
    printf("258\n");
  }

  /* if e is indexed, then this will be a[idx] */
  // if (is_indexed(e)) {
  //   name[pos++] = '[';
  //   name[pos] = 1;
  //   pos += assign_name_to_buf((int **)(name + pos), *e.array.idx);
  //   name[pos++] = ']';
  // }
  printf("Befor access\n");
  name[pos] = '\0';
  printf("After access\n");
  return pos;
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