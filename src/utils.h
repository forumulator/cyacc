#ifndef _CALC
#include "calc.h"
#endif

#define _UTILS
#include <stdio.h>

// NEVER make a list with automatic 
// node variables, always malloc
struct list {
  void *data;
  struct list* next;
};

int is_incompl_type (struct type t);
void list_join (struct list **l, struct list **m);
void list_append_elem (struct list **l, struct list *elem);
void list_prepend_elem (struct list **l, struct list *elem);
struct list *list_create_elem (void *data);
void *list_pop_front (struct list **l) ;

void copy_name (char **, char *);

struct expr_type create_const_expr(char *const_str);
struct expr_type create_const_expr2(int c);
void array_decay (struct expr_type *e);

int is_coercible (struct type to, struct type from);

struct type pointer_deref (struct type t);
struct type arr_reduce_dimen (struct type t);

int is_assignable (struct expr_type e);
int is_equiv(struct type t1, struct type t2);

struct expr_type create_sym_expr (symrec *sym);
int const_type (char *const_str);
int const_val (char *const_str);

void make_label_text (char **buf, int label);
void make_patch_text (char **buf, int patch);

int assign_name_to_buf(char **buf, struct expr_type e);
void temp_var_name(int idx, char *buf);

int digits (int num);
int cstrcpy (char *dest, char *src);

void print_type(struct type t);

void dump_tables();
void dump_sym_tables();
void dump_table (FILE *tfile, struct list *sym_table);
void dump_struct_table ();

struct type get_target_type (struct expr_type e);
char *citostr (const int c);

struct expr_type create_temp_expr (int temp, struct type t);