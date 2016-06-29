// copyio2.c
// KR program 7
// 2nd copyio. putting getchar in the while loop test part

#include <stdio.h>

/* copy input to output 2nd version */
main()
{
	int c;

	while((c = getchar()) != EOF)
	  putchar(c);
}
