#include <stdio.h>

int main()
{
	int a[5] = { 11, 22, 33, 44, 55 };
	int x;

	int* p_a;

	p_a = a; // we don't need to do &a since a is already a pointer

	for( x=0; x<5; x++ )
		printf("%p %p\n",p_a+x, &a[x]);

	return(0);
}
