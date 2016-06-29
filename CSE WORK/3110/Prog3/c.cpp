/***************	
Name:	ASAD WAHEED
Course: CSCE3110
Assignment:	PROGRAM 3
Due	Date:	3-26-2016
****************/


// Libraries
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "BinarySearchTree.h"

using namespace std; 



// Main
int main(int argc, char **argv)
{
	// Build sample test data using 16 integer array
	int NodeValueTestData[16] = { 50,76,21,4,32,64,15,52,14,100,83,2,3,70,87,80 };

	// Binary Search Tree object
	BinarySearchTree testTree; 

	// Test PrintInOrder Function
	cout << "Printing tree in-order\nBefore adding numbers\n";
	testTree.PrintInOrder();

	
	// Iterate and add all 16 integers to the tree following
	// properties of the BST, then print out the tree
	for(int i = 0; i < 16; i++ )
	{
		testTree.AddLeafNode(NodeValueTestData[i]);
	}
	
	cout << "Printing tree in-order\nAfter adding numbers\n";

	testTree.PrintInOrder();
	
	cout << endl;

	int input;
	cout << "Part C.\n\nEnter a key (node value) for deletion. Enter -1 to quit" << endl;
	while(input != -1)
	{
		cout << "Delete Node: ";
		cin >> input;
		{
			if(input != -1)
			{
				cout << endl;
				testTree.RemoveNode(input);
				testTree.PrintInOrder();
				cout << endl;
			}	
		}
	}
	return 0;
}