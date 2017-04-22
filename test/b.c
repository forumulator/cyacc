#include "list.h"
#include <stdio.h>



struct test {
	int val;
	union {
		struct list_elem l;
		int b;
	} pl;
};


int main() {
	int p[6], a = 5;
	float b = 4.2;
	a = (int)b;
	struct test t = {6};
	printf("%d", t.val);
	printf("%d", a);
	// int c = (int) t;
	p[(int)b];
}