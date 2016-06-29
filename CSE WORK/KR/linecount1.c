// linecount1.c
// KR program 10
// Counts number of input lines

#include <stdio.h>


// count lines in input
main()
{
        int c, nl;

        nl =0;
	while((c = getchar()) != EOF)
		if(c == '\n')
		  ++nl;
	printf("%d\n", nl);

}

