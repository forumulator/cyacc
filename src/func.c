#include "calc.h"
#include "utils.h"
#include "func.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct list *func_table;


void print_sym_table(struct list *sym_table) {

	struct list *node = sym_table;
	symrec * rec;
	printf("Symbol Tabl\n");
	while (node) {
		rec = (symrec *)node->data;
		printf("%s %d\n", rec->name, (rec->scope).level);
		node = node->next;
	}
}

struct func_rec *create_func(char *func_name, 
				struct type func_type)
{
	struct func_rec* ptr;
	ptr = (struct func_rec *) malloc(sizeof(struct func_rec));
	ptr->name = (char *) malloc(strlen(func_name) + 1);
	strcpy(ptr->name, func_name);

	ptr->ret_type = func_type;
	ptr->param_list = NULL;
	ptr->sym_table = NULL;
	ptr->num_param = 0;
	
	list_append_elem(&func_table, list_create_elem(ptr));
	return ptr;
}

struct func_rec *search_func(char *func_name)
{
	struct list *node = func_table;
	struct func_rec *func;
	while (node) {
		func = (struct func_rec *)node->data;
		if (!strcmp(func_name, func->name))
			return func;
    node = node->next;
	}
	return NULL;
}

void 
create_param (struct func_rec *f, symrec *sym)
{
	if (!f)
		return;
	(f->num_param)++;
	list_append_elem(&f->param_list, list_create_elem(sym));
	return;
}

symrec *
putsym (struct func_rec *active_func, char *sym_name, 
    struct type sym_type, struct scope_type scope)
{
	// printf("in putsym");
  	// printf("%d\n", active_func);

  struct list *sym_table;
 

  symrec *ptr;
  ptr = (symrec *) malloc (sizeof (symrec));
  copy_name(&ptr->name, sym_name);
  ptr->type = sym_type;
  // ptr->value.var = 0; /* set value to 0 even if fctn.  */
  scope.over = 0;
  ptr->scope = scope;

  if (active_func) {
  	list_append_elem(&(active_func->sym_table), list_create_elem(((void *)ptr)));
  }
  else
  	list_append_elem(&(global_sym_table), list_create_elem(((void *)ptr)));

 	print_sym_table(global_sym_table);

    // sym_table = global_sym_table;
  return ptr;
}

symrec *
getsym (struct func_rec *active_func, 
    char *sym_name, struct scope_type scope)
{
  struct list *sym_table;
  struct list* node;
  symrec *ptr, *ret = NULL;
  if (active_func) {
    sym_table = active_func->sym_table;
    int larg = -1;
    for (node = sym_table; node; node = node->next) {
      ptr = (symrec *)node->data;
        // Check scoping rules too
      // printf("Name: %s, %d\n", ptr->name, scope.level);
      if (!ptr->scope.over && ptr->scope.level <= scope.level
          && scope.level > larg && !strcmp (ptr->name,sym_name)) {
        ret = ptr;
        larg = ptr->scope.level;
      }
    }
  }  
  if (ret)
    return ret;

  // printf("NAme,%s\n", sym_name);
  sym_table = global_sym_table;
  for (node = sym_table; node; node = node->next) {
    // printf("In the thing=========================\n");
    ptr = (symrec *)node->data;
      // Check scoping rules too
    // printf("%s, %s\n", ptr->name, sym_name);

    if (!strcmp (ptr->name, sym_name))
      return ptr;
  }

// ?("ret NULL");
  
  return NULL;

}



// void search_var(node* list, int found, int level
// 	const char* var_name)
// {
// 	node* ptr;
// 	found = 0;
// 	for(ptr = list; ptr != NULL && ptr->level == level;
// 		ptr = ptr->next)
// 	{
// 		if(strcmp(ptr->rec->name, var_name) == 0)
// 		{
// 			found = 1;
// 			break;
// 		}	
// 	}

// }

// void delete_var(struct func_rec* namptr, int level)
// {
// 	node* ptr, temp_ptr;
// 	for(ptr = namptr->var_list; ptr!= NULL && 
// 		ptr->level == level;)
// 	{
// 		remov_sym(node->rec);
// 		ptr =  ptr-> next;
// 		free(namptr->var_list);
// 		namptr->var_list = ptr;
// 	}

// }
