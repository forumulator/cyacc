#include "calc.h"
#include <stdlib.h>
#include <string.h>
#include "utils.h"

// User defined data types 
struct list *cmpnd_types;

// Aliases info.
struct list *aliases;

void
init_tables () {
  aliases = NULL;
  cmpnd_types = NULL;
}

struct struct_type 
*create_struct (char *name, struct memb_list* elems, int incompl) { 
  ss = malloc(sizeof(struct struct_type));
  ss->name = name;

  int size = 0;
  struct memb_list *node = elems;
  while (node) {
    size += size_of(node->typerec);
    node = node->next;
  }
  
  if (incompl) {
    ss->size = -1;
    ss->elems = NULL;
  }
  else {
    ss->size = size;
    ss->elems = elems;
  }

  // Create new node
  struct *list newnode = malloc(sizeof(struct list));
  newnode->data = (void *)ss;
  newnode->next = NULL;

  // Add to current list
  struct list *n = cmpnd_types;
  if (cmpnd_types) {
    while (n->next)
      n = n->next;
    n->next = newnode;
  }                        
  else
    cmpnd_types = newnode;
  return ss;
}

struct memb_list *
create_member (char *name, struct memb_list *join) {
  struct memb_list *this = malloc(sizeof(struct memb_list));
  copy_name(&this->name, name);
  this->next = join;
  return this;
}

struct struct_type 
*get_struct (char *name) {
  struct list *node = cmpnd_types;
  struct struct_type *s;
  while (node) {
    s = (struct struct_type *)node->data;
    if (!strcmp(s->name, name))
      return s;
    node = node->next;
  }
  
  // No match
  return NULL;
}

struct type 
struct_get_elem (struct struct_type *stype, char *name) {
  struct memb_list *node = stype->elems;
  while (node) {
    if (!strcmp(node->name, name))
      return node->typerec;
    node = node->next;
  }

  struct type t; t.ttype = UNDEF_TYPE;
  return t;
}

int 
struct_calc_offset (struct struct_type *stype, char *name) {
  struct memb_list *node = stype->elems;
  int offset = 0;
  while (node) {
    if (!strcmp(node->name, name))
      return offset;
    offset += size_of(node->typerec);
    node = node->next;
  }

  return -1;
}

symrec *
putsym (sym_name, sym_type)
     char *sym_name;
     struct type sym_type;
  {
    symrec *ptr;
    ptr = (symrec *) malloc (sizeof (symrec));
    copy_name(&ptr->name, sym_name);
    ptr->type = sym_type;
    // ptr->value.var = 0; /* set value to 0 even if fctn.  */
    ptr->scope.level = depth;  ptr->scope.label = nlabel;
    ptr->scope.over = false;
    list_append_elem(&sym_table, list_create_elem(((void *)ptr)));
    return ptr;
  }

symrec *
getsym (sym_name)
     char *sym_name;
{
  struct list* node;
  symrec *ptr;
  for (node = sym_table; node; node = node->next) {
    ptr = (symrec *)node->data;
      // Check scoping rules too
    if (!ptr->scope.over && ptr->scope.level <= depth
        && !strcmp (ptr->name,sym_name))
      return ptr;
  }
  
  return 0;
}

void
delsym_scope(int depth) {
  struct list *node; symrec *ptr;
  for (node = sym_table; node; node = node->next) {
    ptr = (symrec *)node->data;
    if (!ptr->scope.over && ptr->scope.depth == depth)
      ptr->scope.over = true;
  }
  return;
}

struct type *
get_alias (char *name) {
  struct list *node = aliases;
  struct alias_rec *alias;
  while (node) {
    alias = (struct alias_rec*)node->data;
    if (!strcmp(alias->name, name)) 
      return &alias->to;
    node = node->next;
  }

  // Alias not found
  return NULL;
}

void
create_alias (struct type t, char *name) {
  // Check if identifier 
  // is in the symbol table              
  struct list *node = aliases, *last = aliases;
  struct alias_rec *alias; int exis_flag = 0;
  while (node) {
    last = node;
    node = node->next;
  }

  if (exis_flag)
    goto done_alias;

  node = create_alias_entry($3, $2);
  if (aliases)
    last->next = node;
  else 
    aliases = node;

  return;
}

struct list *
create_alias_entry(char *name, struct type tar) {
  struct alias_rec *alias = malloc(sizeof(struct alias_rec));
  alias->name = malloc(strlen(name) * sizeof(char));
  strcpy(alias->name, name);
  alias->to = tar;
  struct list *node = malloc(sizeof(struct list));
  node->next = NULL;
  node->data = (void *)alias;
  return node;
}