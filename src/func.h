#ifndef _CALC
#include "calc.h"
#endif

#ifndef _UTILS
#include "utils.h"
#endif


extern struct list *func_table;

struct func_rec {
	int defined;
	int label;
	char *name; // name of the symbol
	struct type ret_type; // result type of the function
	struct list *param_list; // list containing the parameters
	struct list *sym_table;
	int num_param;
};

struct func_rec *create_func(char *func_name, 
				struct type func_type);
struct func_rec *search_func(char *func_name);
void create_param (struct func_rec *f, symrec *sym);

symrec *putsym (struct func_rec *active_func, char *sym_name, 
    struct type sym_type, struct scope_type scope);
symrec *getsym (struct func_rec *active_func, 
    char *sym_name, struct scope_type scope);

void print_sym_table(struct list *sym_table);