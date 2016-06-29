// Tutorial 24 - Reading From a File 
// Source: https://www.youtube.com/watch?v=6vEf4n6NQtY
// Reading Data from a Text File 


// Includes 

#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{

	char filename[50];	//user's input

	ifstream ifile;
	cin.getline(filename,50);

	ifile.open(filename);

	if(!ifile.is_open())
	{
		cout << " file is open hoss! " << endl;
		exit(EXIT_FAILURE);	//cstdlib call
	}

	char word[50];
	ifile >> word; 
	while(ifile.good())	//as long as we arrent to the end of the file
	{
		cout << word << " ";
		ifile >> word;
	}
	
	printf("\n\nCLOSING FILE...DONE\n\n");
	ifile.close();

// system ("pause"); awesome, system DOESNT WORK ON LINUX GUYS
			      //HOW COOL IS THAT
return 0;
}
