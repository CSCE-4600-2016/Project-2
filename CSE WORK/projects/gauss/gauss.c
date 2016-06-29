// Simple implementation of the gauss elimination from
// linear algebra

#include <math.h>
#include <stdio.h>

int main()
{
	// create and populate matrix

	double matrix[16][16];
	double b[16], x[16];

	int n, i, count, j;
	double ratio, temp;


	// Read in matrixes a and b

	scanf("Enter size of matrix: %d ",&n );
	printf("\nThe matrix is %d by %d\n", n, n );
	printf("Matrix:\n ");

	for( i = 0; i < n; i++ )
	{
	  for ( j = 0; j < n; j++ )
	  {
		/* Comment out below line for a normal matrix, otherwise we are impl
		-ementing a Hilbert matrix */

		matrix[i][j] = 1;
	  }
	}

	return 0;
}
