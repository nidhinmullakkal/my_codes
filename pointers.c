#include <stdio.h>
int main()
{
	int a;
	int *p;

	scanf("%d", &a);
	p = &a;
	printf("%d", *p);
	
	return 0;
}

