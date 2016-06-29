// Reading data from custom file structures

// Bucky source video: https://www.youtube.com/watch?v=EjJY7yA5SWw


// includes 

#include <iostream> 
#include <fstream> 
#include <string>
using namespace std; 

int main()
{
	ifstream theFile("P2_2110_Test_A(1).csv");

	string command1;
	string command2;
	string node;
	string node2;


	while(theFile >> command1 >> command2 >> node >> node2)
	{
		cout << "\nFILE PROCESSED SUCCESFULLY \n\n";
		cout << command1 << " " << command2 << " " << node << " " << node2 << endl;
	}


	theFile.close();

	return 0;
}
