
/*
    Asad Waheed
    File: Sort.cpp
    Desc: Implementing all the header file prototypes
*/

#include "Sort.h"

using namespace std;

int Sort::testfunc1()
{
return 1;
}

void Sort::displayMenu()
{
	cout << "======================================================" << endl;
	cout << "\n\tPROGRAM 2: CENSUS DATA PROCESSOR\n";
	cout << "\n======================================================\n\n" << endl;
	cout << "\n\n Choose one of the following options:\n";
	cout << "\n1. Run MergeSort";
	cout << "\n2. Run QuickSort";
	cout << "\n3. Run QuickSort+InsertionSort Hybrid";
	cout << "\n4. QUIT\n\n\n";

	char choice;

	while(1)
	{
	cin >> choice;
	switch(choice)
	{
		case '1':
			cout << "PIZZA"; 
			break;
		case '2':
			break;
		case '3':
			break;
		case '4':
			break;
		default:
			cout << "\nBAD INPUT TRY AGAIN.";
			break;
	}
	}

}
