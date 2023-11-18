#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	/* these strings are in the text section of the elf along with the function instructions 
	04_03-weekdays1.o:     file format elf64-x86-64

Contents of section .text:
 0000 554889e5 4883ec60 48b85375 6e646179  UH..H..`H.Sunday
 0010 00004889 45b066c7 45b80000 48b84d6f  ..H.E.f.E...H.Mo
 0020 6e646179 00004889 45ba66c7 45c20000  nday..H.E.f.E...
 0030 48b85475 65736461 79004889 45c466c7  H.Tuesday.H.E.f.
 0040 45cc0000 48b85765 646e6573 64614889  E...H.WednesdaH.
 0050 45ce66c7 45d67900 48b85468 75727364  E.f.E.y.H.Thursd
 0060 61794889 45d866c7 45e00000 48b84672  ayH.E.f.E...H.Fr
 0070 69646179 00004889 45e266c7 45ea0000  iday..H.E.f.E...
 0080 48b85361 74757264 61794889 45ec66c7  H.SaturdayH.E.f.
 0090 45f40000 488d3d00 000000e8 00000000  E...H.=.........
 00a0 c745fc00 000000eb 32488d4d b08b45fc  .E......2H.M..E.
 00b0 4863d048 89d048c1 e0024801 d04801c0  Hc.H..H...H..H..
 00c0 4801c848 89c6488d 3d000000 00b80000  H..H..H.=.......
 ....snip....
 0230 00e80000 00008345 fc01837d fc067ec8  .......E...}..~.
 0240 b8000000 00c9c3                      .......
Contents of section .rodata:
 0000 556e736f 72746564 3a002025 730a0053  Unsorted:. %s..S
 0010 6f727465 643a00                      orted:.
	
	
also see https://stackoverflow.com/questions/62680568/do-arrays-that-get-allocated-on-the-stack-within-the-scope-of-a-function-always

	*/
	char weekdays[7][10] = {
		"Sunday", "Monday", "Tuesday", "Wednesday",
		"Thursday", "Friday", "Saturday"
	};
	char temp[10];
	int x,y;

	/* output original array */
	puts("Unsorted:");
	for( x=0; x<7; x++ )
		printf(" %s\n",weekdays[x]);

	/* sort the array, bubble sort */
	for( x=0; x<6; x++ )
	{
		for( y=x+1; y<7; y++ )
		{
			/* Sort alphabetically, A to Z */
			if( strcmp(weekdays[x],weekdays[y]) > 0 )
			{
				strcpy(temp,weekdays[x]);
				strcpy(weekdays[x],weekdays[y]);
				strcpy(weekdays[y],temp);
			}
		}
	}

	/* output the sorted result */
	puts("Sorted:");
	for( x=0; x<7; x++ )
		printf(" %s\n",weekdays[x]);

	return(0);
}
