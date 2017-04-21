#include "utils.h"

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
  ret.size /= t.array.dimen[0];

  int i;
  for (i = 1; i < t.array.n; ++i)
    ret.array.dimen[i - 1] = t.array.dimen[i];
  ret.array.n = t.array.n - 1;
  return ret;
}

struct type
pointer_deref (struct type t) {
  struct type ret;
  ret.type = UNDEF_TYPE;
  if (is_array(t))
    return arr_reduce_dimen(t);
  else if (!is_pointer(t))
    return ret;

  return *(t.val.ptr_to);
}

struct expr_type 
create_const_expr (char *const_str) {
  struct expr_type e; t.type.ttype = UNDEF_TYPE;
  if (!const_str)
    return e;

  e.type = get_const_type(const_str);
  e.ptr = CONST_PTR;
  e.val.const_str = const_str;

  return e;
}

struct expr_type
create_sym_expr (symrec *sym) {
  struct expr_type ret; 
  ret.type.ttype = UNDEF_TYPE;
  if (!sym)
    return ret;

  ret.ptr = SYM_PTR; 
  ret.type = sym->type;  // Think about it: redundancy, how to eliminate
  ret.val.sym = sym;

  return ret; 
}

struct 
const_type (char *const_str) {
    /* TODO: Maybe set the type
    * from the lexer itself */
    return INT;
}

int
is_coercible (struct type to, struct type from) {
    if (to.ttype == COMPOUND_TYPE || from.type == COMPOUND_TYPE)
        return 0;
    if (is_int_type(to))
        return 2;
    if (to.ttype == PTR_TYPE && from.ttype == PTR_TYPE)
        return 1;
    return (to == from);
}

void 
copy_name (char **buf, char *name) {
  if (!name)
    return;
  *buf = malloc((strlen(name)  + 1)* sizeof(char));
  strcpy(*buf, name);
  return;
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