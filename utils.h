#include "calc.h"


// NEVER make a list with automatic 
// node variables, always malloc
struct list {
  void *data;
  struct list* next;
};

void list_join (struct list **l, struct list **m);
void list_append_elem (struct list **l, struct list *elem);
void list_prepend_elem (struct list **l, struct list *elem);
struct list *list_create_elem (void *data);
void *list_pop_front (struct list **l) ;

void copy_name (char **, char *);

struct expr_type 
create_const_expr(char *const_str);

int 
size_of (struct type t);