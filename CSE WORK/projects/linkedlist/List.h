#ifndef LIST_H
#define LIST_H

class List
{
   private:

	typedef struct node
	{
	   int data;
	   node* next;		// next pointer for the next element in the list
	   
	} *nodePointer;


	nodePointer head; 	//head pointer
	nodePointer current;
	nodePointer temp;
   public:			//functions go here

	List();			// constructor to set the nodePointer values

	void addNode(int addData);

	void deleteNode(int deleteData);

	void printList();

};



#endif
