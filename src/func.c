#include "calc.h"
#include "utils.h"
#include "func.h"
#include <stdlib.h>
#include <string.h>

struct list *func_table;

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