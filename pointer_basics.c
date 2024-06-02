#include <stdio.h>
#include <string.h>
int main()
{
	int *ptr;
	int **p;
	int a = 10;
	ptr = &a;

	p = &ptr;
	printf("\n%d", **p);

	int x[] = {0, 1, 2, 3, 4};
	ptr = x;
	printf("\n%d", *(ptr+4));
	printf("\n%d", 10+**p);
	char c = 'c';
	char k[]={'g','t','p'} ; 
	char *d;
	d = k;
	printf("\n%c", *(d+2));

	return 0;
}
