// temp_convert_variation.c
// KR program 4 
// Using a for loop for temp conversion

#include <stdio.h>

/* print Fahrenheit-Celsius table */

main()
{
	int fahr;

	// for loop implementation

	for (fahr = 0; fahr <= 300; fahr = fahr + 20)
		printf("%3d %6.1f\n", fahr, (5.0/9.0)* (fahr - 32)); 

	system("pause");
}
