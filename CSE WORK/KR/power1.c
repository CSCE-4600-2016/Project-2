// KR program 13
// Functions
// Creating an exponent function

#include <stdio.h>

/* protoype */
int power(int m, int n);

main()	// Tests the power function
{
	int i;

	for( i = 0; i < 10; ++i)
		printf("%d %d %d\n", i, power(2,i), power(-3,i));

	return 0;
}

/* power: raise base to the n-th power where n >= 0*/
int power(int base, int n)
{
	int i, p;
	
	p = 1;

	for( i = 1; i <= n; ++i)
		p = p * base;
	return p;
}
