/*************************************************************
* Name: Asad Waheed											 *
* Course:CSCE 3110											 *
* Assignment: Programming Assignment 1 - Starter Program	 *
* Due Date: 01-23-2016										 *
*************************************************************/

/* PROGRAM DESCRIPTION
The main program should:
Declare a 2-D, 10x10 array

Call two functions:

Input function: Uses standard input (scanf or cin) to read in the values into a 2-D array.

Output function: Uses standard output (printf or cout) to output the values from the array formatted as below array
formatted as below

10 integers, on 10 lines

*/

// Libs
#include <iostream>	//	cin,cout, getline
#include <fstream>	// ifstream object
#include <string>	

using namespace std;

// Global vars
extern const int SIZE = 10;
int matrix[SIZE][SIZE];

// input function 
void input() 
{
	// ifstream object and uninitialized char...may need it later
	ifstream in("program1input.dat"); 
	char ch;
	
}

// output function 
void output(ifstream &in, char ch)	// Pass a reference to a file stream obj. and a character
{
	while (!in.eof())	// When the file buffer reaches end-of-file, while-loop stops 
	{
		in.get(ch);		// gets chars one at a time; get() is inherited from istream
		cout << ch;		// output one char at a time
	}
	in.close();			// Close file; we are done now
	cout << endl;		// Aesthetics
	
	
}

// main -- entry point of the program
int main()
{
	// Variables to pass to functions

	ifstream test("program1input.dat");
	char c = ' ';

	// function calls
	input();
	output(test, c);

	return 0; // exit program
}

// PROGRAM REFERENCES: 
// C File Handling: http://www.thecrazyprogrammer.com/2015/02/file-handling-in-c-part-1.html
// How to pass ifstream object as a func arg: http://stackoverflow.com/questions/4980810/how-to-pass-cin-or-ifstream-object-as-argument-function
// fopen() reference info: http://pubs.opengroup.org/onlinepubs/009695399/functions/fopen.html