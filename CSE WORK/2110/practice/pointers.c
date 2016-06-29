// Trying out more pointer practice in C


#include <stdio.h> 
#include <stdlib.h> 

//using namespace std; 

int main()
{
	int *p1; 
	int x;
	int *p3;
	int [p3]array;

	p1 = &x;
	printf("Enter a value:\t");
	scanf("%d", &x);
	printf("\npointer memory address value of p1: %p\n\n", p1);
	printf("\npointer's value:\t%d\n", *p1);
	return 0;
}
