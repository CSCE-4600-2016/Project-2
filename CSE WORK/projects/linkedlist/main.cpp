// Using main to test the List class implementation


// libraries
#include <cstdlib>
#include "List.h"


int main(int argc, char ** argv)
{
	// Objects
	List Linkedlist; 

	// Sample data
	Linkedlist.addNode(3);
	Linkedlist.addNode(5);
	Linkedlist.addNode(7);

	Linkedlist.printList();

	// Deletion
	Linkedlist.deleteNode(3);

	// Display
	Linkedlist.printList();

	// Check non-members
//	Linkedlist.deleteNode(1);

	return 0; 

}
