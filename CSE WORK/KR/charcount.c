// charcount.c
// KR program 8
// Counts the number of characters

#include <stdio.h>

/* count characters in input; 1st version */
main()
{
	long nc;

	nc = 0;
	while (getchar() != EOF)
	  ++nc;
	printf("&ld\n", nc);
}
