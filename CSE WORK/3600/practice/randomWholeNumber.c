/*
	This program initializes a 128x128 matrix with random values
	and increments/decrements using 3-2D arrays
	Adapted from Dr. Sweany's program whole.c
	Asad Waheed
*/


#include <stdio.h>

// CONSTANT for array size

#define SIZE 256

// Creating 3 arrays of int type
int A[SIZE][SIZE],
    B[SIZE][SIZE],
    C[SIZE][SIZE];

// Function prototypes 

void randomizeValues(int dim, int);
void computeElement(int, int);
void print();

// Main function

int main()
{
	/*for loop variables*/
	int i,j;

	// Populate the 2D arrays A and B with random values
	randomizeValues(SIZE, 100);	//initialize big to 0

	// Call computeElement
	for( i = 0; i < SIZE; i++ )
	   for( j = 0; j < SIZE; j++ )
		computeElement(i,j);	//do the loops get passed as function arguments?

	// Call print and some extra formatting
	print();
	printf("\n---------------------------------\n");
	printf("\n...Computation complete...\n\n");
	printf("\n---------------------------------\n");


	return 0;
}


// Value randomizing function explicit definition

void randomizeValues(int dim, int big)
{
	int i, j;	// for loop variables
	for( i = 0; i < dim; i++ )
	   for( j = 0; j < dim; j++ )
	   {
		A[i][j] = random() % big;	// "big" is a user-defined modulo
		B[i][j] = random() % big;
	   }
}

// Compute elements function explicit definition

void computeElement(int rowNumber, int colNumber)
{
	int sum = 0;
	int k;	//for loop counter
	C[rowNumber][colNumber] = 0;	//initialize matrix indices to 0
	for ( k = 0; k < SIZE; k++)
	{
		// Checks if remainder of k is 2
		if( k % 2 )
		{
			// C increments by the product of A and B
			C[rowNumber][colNumber] += A[rowNumber][k] * B[k][colNumber];
		}
		else
		{
			// C decrements by the product of A and B
			C[rowNumber][colNumber] -= A[rowNumber][k] * B[k][colNumber];
		}
	}
}

// Print (display) function for stdout in console

void print()
{
	// for loop vars
	int i,j; 

	for( i = 0; i < SIZE; i++)
	   for(j = 0; j < SIZE; j++)
	      printf("C[%d][%d] = %d\n", i, j, C[i][j]);
}
