// Asad Waheed
// Example of the Selection Sort from textbook, page 31
// Date: 06 - 12 - 2015

#include <iostream>
#include <stdio.h>

using namespace std;

// I am intentionally putting SelectionSort function first in order to
// avoid having to do any function prototypes.
// Just a simple example.

void SelectionSort(int A[], int n)	// function takes an int array &
					// an int n variable
{
    int i, j, small, temp;
    for(i=0; i < n-1; i++)
    {
	// set small to the index of the first occur-
	// rence of the smallest element remaining

	small = i;

	for(j = i+1; j < n; j++)
	  if(A[j] < A[small])
		small = j;
	/*
		When we reach here, small is the
		index of the first smallest element
		in A[i...n-1];
		we now exchange A[small] with A[i]
	*/

	temp = A[small];
	A[small] = A[i];
	A[i] = temp;
    }
}

int main()
{
	int arr[] = {2,3,4,19,81,12,21,14,6,32};
	int num; 
	SelectionSort(arr, num); 
 return 0;
}

