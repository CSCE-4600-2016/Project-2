/*
	Implementation file for Linkedlist

*/

#include <cstdlib>
#include <iostream>

#include "List.h"

using namespace std;

// Constructor - setting the default values of our private members

List::List()
{
	head = NULL;
	current = NULL;
	temp = NULL;
}

void List::addNode(int addData)
{
	// creating a new node and making the nodePointer point to it
	nodePointer n = new node;

	// set n to last element
	n->next = NULL;

	// fill n with data

	n->data = addData;

	// If >= 1 element in list

	if(head != NULL)
	{
	   current = head;

	   while(current->next != NULL) //check for last element in list
	   {
		current = current->next; 
	   } 
	   current->next = n; 	//next element is gonna point to n
	}
	else	// otherwise make the head our new node pointer
	{
		head = n; //becomes the front of the list
	}
}


void List::deleteNode(int deleteData)
{
	nodePointer deletePointer = NULL;	// set to null
	temp = head;
	current = head;

	// Check if current node is the one to be deleted
	// Temp is our walker (follows current pointer)
	while(current != NULL && current->data != deleteData)
	{
		// advance pointer
		temp = current;
		current = current->next;
	}
	if(current == NULL) // if we're at the end of the list
	{
		cout << deleteData <<" was not in the list\n";
	} 
	else 
	{
	
	   deletePointer = current;
	   current = current->next; // advances current
	   temp->next = current;    // follows current
	   
	   // if we delete the head...
	   if(deletePointer == head)
	   {
		head = head->next;
		temp = NULL;
	   }
	   delete deletePointer;    // remove the node its pointing to
	   cout << " The value " << deleteData << " was deleted\n";
	}
	
	// shit...i hope this works 0_0

}


void List::printList()
{
	current = head;
	while(current != NULL)
	{
		cout << current->data << endl;
		current = current->next;
	}
}
