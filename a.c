#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "b.h"

int sq(int x) {
	return x*x;
}

int abdf = 2;
typedef int intt;
typedef int intt;

int main() {

	printf("%x\n", &abdf);
	// ptr();
	int a = 6, b = 4;
	// b = sq(a) + 2; int d= 2;
	// struct c
	// typedef int a b;
	// struct c;
	// struct vv u, v;
	int *q;
	char  *(*p)[5];
	// int an[][4] = {1, 2, 3, 4};
	// p = &an;
	int aaa[5] = {1, 2, 3, 4, 5};
	p = &aaa;
	printf("%d, %d, %d\n", sizeof(char *), sizeof(*q), sizeof(*p));
	printf("%x, %x, %x\n", &(p[5]), &((*p)[100]), aaa);
	// printf("p[2]: %d\n", sizeof(int a[5][5]));
	// u.d = 5;
	// printf("%d\n", (v = u).d);
	if (a == 6) {
		a += 2;
	} b = 5;

	// struct d {
	// 	struct c b;
	// 	int d;
	// };
	// struct sgv ff;
	// struct c d;
	// printf("%d\n", strcmp("abc", ""));

	// struct c {char d = 4,e, f;};
	// struct b c;
	// printf("%d\n", sizeof(struct c));
}