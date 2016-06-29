/* Simple Pascal Triangle Program
 * Pascal's Triangle has many different
 * applications in combinatorics, counting
 * numbers, even/odd numbers, factorials,
 * perfect squares, and more!
*/

// This program prints Pascal's triangle to the console
// given a user-defined number of rows

#include <iostream>

using namespace std;	// too lazy to use :: operator
int main()
{
	int rows;
	cout << "Enter number of rows:  " << endl;
	cin >> rows;
	cout << endl;	//aesthetics

	for( int i = 0; i < rows; i++ )
	{
	  int value = 1; 
	
	  for( int j = 1; j < ( rows - i ); j++ )
	  {
		cout << "  ";
	  }
	
	  for( int k = 0; k <= i; k++ )
	  {
		cout << "    " << value;
		value = value * ( i - k )/ ( k + 1 );
	  }

	  cout << endl << endl;
	}
	
	cout << endl;

	return 0;
}

