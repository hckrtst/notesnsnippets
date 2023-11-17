#include <stdio.h>
#include <stdlib.h>

void fill(int *n) // this pointer is a local copy
{
	int x;

	// oops: we only updated the local copy and not the one that the caller has!
	n = (int *)malloc( sizeof(int) * 4);
	if( n==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	for(x=0; x<4; x++)
	{
		*(n+x) = (x+1)*11;
		printf("%d ",*(n+x) );
	}
	putchar('\n');
}

int main()
{
	int *numbers;// a pointer to one or more integers
	int x;

	fill(numbers);
	for(x=0; x<4; x++)
	{
		printf("%d ",*(numbers+x) ); // this prints garbage or crashes
	}
	putchar('\n');

	return(0);
}
