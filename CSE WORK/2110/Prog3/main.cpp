// Asad Waheed Team F
// CSCE 2110
// Program: Adjacency Matrix Map v1.0
// First iteration of a simple graph-based map program

/*
	Sources:
	partially used (source): http://www.sanfoundry.com/cpp-program-implement-adjacency-matrix/
	CSCE2100 Summer 2015 Program 4 - Family Tree (I used it to build the cmd> prompting component)

*/


#include <iostream>	// cin, cout
#include <cstdlib>
//#include <conio.h>	// getch();
#include <curses.h>
#include <ncurses.h>
#include <sstream>
#include <stdlib.h>
#include <fstream>
//#include "functions.h"
// adjacency matrix test implementation

using namespace std;

// constant 
#define MAX 26


/*	
	
	Adjacency Matrix Class
	This class will be abstracted to a separate file and called with headers later
	
*/

class AdjacencyMatrix
{
	private:		//	need to make these members private to encapsulate data 
	int n;			
	int **adj;		//	essentially an array of pointers 
	bool *visited;  //	pointer to check if we have visited the index of the array

	public:
	AdjacencyMatrix(int n) //	overloaded constructor to initialize the data
	{
		this->n = n;
		visited = new bool[n];
		adj = new int* [n];
		for (int i = 0; i < n; i++)
		{
			adj[i] = new int[n];

			for (int j = 0; j < n; j++) // Populate the matrix with zeroes by default 
			{
				adj[i][j] = 0;
				
			}
		}
	}

	/*
	
	* Adding Edge to Graph
	
	*/

	void add_edge(int origin, int destin)
	{
		if (origin > n || destin > n || origin < 0 || destin < 0) // cannot have negative distances!!
		{
			cout << "Invalid edge!\n"; 
		}
		else
		{
			adj[origin - 1][destin - 1] = 1;	// adds a node if the edge is not an invalid value
		}
	}

	/*
	
	* Print the graph

	*/

	void display()	// displaying the matrix to console/terminal
	{
		int rows, columns; 

		for (rows = 0; rows < n; rows++)
		{
			for (columns = 0; columns < n; columns++)
				
				cout << adj[rows][columns] << " ";
			cout << endl;
		}
	}
};

// Main function 

int main()
{
	string input;
	string addedge = "add edge";
	bool flag = true;	// my check for correct input
	// Command line prompter 
	while (flag) {
		printf("cmd>");
	
		cin >> input; 

		for (int i = 0; i < input.length(); ++i)
		{
			input[i] = tolower(input[i]);
		}//convert string to lowercase

		/* From the summer 2100 program 4 */
		if (input == "add" || input == "search" || input == "remove" || input == "print" || input == "file" || input == "quit" || input == "ftree")
		{//if input matches one of the menu items break loop
			flag = false;
		}
		else
		{
			std::cout << "Invalid input" << std::endl;
		}//input was not correct

		//add edge option
		if (input == "add") 
		{
			string input2;			/* From the summer 2100 program 4 */
			cin >> input2;			/* From the summer 2100 program 4 */
			if (input2 == "edge")	/* From the summer 2100 program 4 */
			{
				cout << " \nadd edge selected\n";
				
				// Graph components we need for it to work
				int
				nodes,
				max_edges,
				origin,
				destin;

				//User Input testing lines 91-92. Comment out line 93 and remove comments from 91-92 to set an arbitrary size of the matrix
				//cout << "Enter size of square matrix: ";
				//cin >> nodes;
				nodes = MAX;	// for A through Z, 26

				AdjacencyMatrix demo(nodes);	// Instantiates a AdjacencyMatrix object called demo

				max_edges = nodes * (nodes - 1); // how i'm defining a graph parameters for simplicity's sake

				// Prompt the user to enter coordinates in the form of two integer values
				// separated by a space
				for (int i = 0; i < max_edges; i++)
				{
				cout << "Enter edge (-1 -1 to exit): ";
				cin >> origin >> destin;
				if ((origin == -1) && (destin == -1))
				break; // stops the input
				demo.add_edge(origin, destin);
				}

				// Displaying the Adjacency Matrix object  to console using display function
				cout << "\nMATRIX  NODE LOCATIONS:\n"
				<< "-----------------------\n\n";
				demo.display();
				getch();
				
			} else 
				if (input2 == "node")
				{
					cout << "add node selected" << endl; 
				} //else if (input2 == )

		}
	}
	
	return 0;
}
