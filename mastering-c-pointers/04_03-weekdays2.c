#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	/*
	
	these strings are now in rodata section of the elf

	04_03-weekdays2.o:     file format elf64-x86-64

Contents of section .text:
 0000 554889e5 4883ec50 488d0500 00000048  UH..H..PH......H
 0010 8945b048 8d050000 00004889 45b8488d  .E.H......H.E.H.
 0020 05000000 00488945 c0488d05 00000000  .....H.E.H......
 ...snip.....
 0140 8345fc01 837dfc06 7ed8b800 000000c9  .E...}..~.......
 0150 c3                                   .
Contents of section .rodata:
 0000 53756e64 6179004d 6f6e6461 79005475  Sunday.Monday.Tu
 0010 65736461 79005765 646e6573 64617900  esday.Wednesday.
 0020 54687572 73646179 00467269 64617900  Thursday.Friday.
 0030 53617475 72646179 00556e73 6f727465  Saturday.Unsorte
 0040 643a0020 25730a00 536f7274 65643a00  d:. %s..Sorted:.
	
	
	*/

	char *weekdays[7] = {
		"Sunday", "Monday", "Tuesday", "Wednesday",
		"Thursday", "Friday", "Saturday"
	};
	char *temp;
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
				temp = weekdays[x];
				weekdays[x] = weekdays[y];
				weekdays[y] = temp;
			}
		}
	}

	/* output the sorted result */
	puts("Sorted:");
	for( x=0; x<7; x++ )
		printf(" %s\n",weekdays[x]);

	return(0);
}
