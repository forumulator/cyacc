	#include <stdio.h>
	#include <math.h>

	struct mulsym {
		int op;
		char *str;
	};

	putsym (sym_name,sym_type)
	     char sym_name;
	     int sym_type; {
	     	printf("%d %c\n", sym_type, sym_name);
	     return 5.5;
	     }
	int a = 3; 

	int main() {

		FILE *f1 = fopen("t.txt", "r+");
		int b[10];
		int a = 3;
		int n = 1;int m = 2;
		(a) = 4;
		// (a + 2)++;
		char c = 5;
		while ((c = getc(f1)) != '(');
		int pos = ftell(f1);
		printf("Pos:%d\n", pos);
		fseek(f1, pos, SEEK_SET);
		fputc('_', f1);
		c(5);
		// struct mulsym *bb = {{1, "++"}, {2, "--"}};

		
		printf("%d, %d\n", &putsym, putsym + a);
	}