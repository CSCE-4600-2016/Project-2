// charcount2.c
// KR program 9
// 2nd iter of prog 8
// Using double to store more memory & a for loop instead of while 

#include <stdio.h> 

/* count characters in input; 2nd version */
main()
{
	double nc; 

	for(nc = 0; getchar() != EOF; ++nc)
		;
		printf("%.0f\n", nc);

}
