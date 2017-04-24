#include "calc.h"
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "func.h"
#include "gramm.h"
#include <stdio.h>

// User defined data types 
struct list *cmpnd_types;

// Aliases info.
struct list *aliases;
struct list *global_sym_table;

struct btype_info
basic_types[] = {
  {"void", 0},
  {"char", 1},
  {"int", 4},
  {"float", 4},
  {"short", 2},
  {"long", 8}
};

void
init_tables () {
  aliases = NULL;
  cmpnd_types = NULL;
  func_table = NULL;
  global_sym_table = NULL;
  int i = 0;
  for (i = 0; i < 6; ++i) {
    basic_types[i].t.ttype = BASIC_TYPE;
    basic_types[i].t.val.btype = i;
    SET_NOT_ARRAY(basic_types[i].t);
  }
}

// incompl parameter to differentiate between 
// empty struct and fwd. declaration
struct struct_type 
*create_struct (char *name, struct memb_list* elems, int incompl) { 
  struct struct_type *ss = malloc(sizeof(struct struct_type));
  copy_name(&ss->name, name);
  // printf("Creating a struct with name %s\n", name);
  int size = 0;
  struct memb_list *node = elems;
  while (node) {
    size += size_of(node->type);
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
  list_append_elem(&cmpnd_types, list_create_elem(ss));
  return ss;
}

struct memb_list *
create_member (char *name, struct memb_list *join) {
  struct memb_list *this = malloc(sizeof(struct memb_list));
  copy_name(&this->name, name);
  this->type.ttype = INCOMPL_TYPE;
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
  // printf("Struct not found");
  // No match
  return NULL;
}

// Get element by offset
// Get element by offset
struct type 
struct_get_elem (struct struct_type *stype, int oft) {
  struct memb_list *node = stype->elems;
  int count = 0;
  while (node) {
    if (oft == count)
      return node->type;
    // printf("c: %d, ", count);
    count += size_of(node->type);
    node = node->next;
  }
  printf("\n");
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
    offset += size_of(node->type);
    node = node->next;
  }

  return -1;
}



void
delsym_scope(int depth) {
  struct list *node; symrec *ptr;
  for (node = global_sym_table; node; node = node->next) {
    ptr = (symrec *)node->data;
    if (!ptr->scope.over && ptr->scope.level == depth)
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

static struct list *
create_alias_entry(char *name, struct type tar) {
  struct alias_rec *alias = malloc(sizeof(struct alias_rec));
  copy_name(&alias->name, name);
  alias->to = tar;
  struct list *node = malloc(sizeof(struct list));
  node->next = NULL;
  node->data = (void *)alias;
  return node;
}

void
create_alias (char *name, struct type t) {
  // Check if identifier 
  // is in the symbol table              
  struct list *node = aliases, *last = aliases;
  struct alias_rec *alias;
  while (node) {
    last = node;
    node = node->next;
  }

  node = create_alias_entry(name, t);
  if (aliases)
    last->next = node;
  else 
    aliases = node;

  return;
}

int 
size_of (struct type t) {
  return t.array.size * base_size_of(t);
  // if (t.array.size >= 0)
  //   return size * t.array.size;
  // else return -1;
} 

int
base_size_of (struct type t) {
  int size;
  if (t.ttype == BASIC_TYPE) 
    size = basic_types[t.val.btype].size;
  else if (t.ttype == PTR_TYPE)
    size = SIZEOFPTR;
  else if (t.ttype == COMPOUND_TYPE)
    // Struct or union
    size = (t.val.stype)->size;
  return size;
}