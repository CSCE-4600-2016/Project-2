// Asad Waheed
// Libraries
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "BinarySearchTree.h"

using namespace std; 

// Constructor
BinarySearchTree::BinarySearchTree()
{
	rootNode = NULL;
}

// Destructor, cleans up and removes the tree once it's out of scope of the program
BinarySearchTree::~BinarySearchTree()
{
	RemoveSubtree(rootNode);
}

// Create a new leaf node, pass in node's value, init right and left pointers to empty (NULL)
BinarySearchTree::BinarySearchTreeNode* BinarySearchTree::CreateNewLeafNode(int nodeValue)
{
	BinarySearchTreeNode* newNode = new BinarySearchTreeNode;
	newNode->nodeValue = nodeValue;

	newNode->leftChildNode = NULL;
	newNode->rightChildNode = NULL;

	return newNode;
}

// Getter function to add a new leaf to the tree
void BinarySearchTree::AddLeafNode(int nodeValue)
{
	AddPrivateLeafNode(nodeValue, rootNode);

}

// Adds a new leaf to the tree recursively
// Performs checking to satisfy BST properties which are:
// Left child strictly less than current node
// Right child strictly greater than current node
// Handling duplicates is its own case
void BinarySearchTree::AddPrivateLeafNode(int nodeValue, BinarySearchTreeNode* ptr)
{
	// If root is not pointing anywhere
	if(rootNode == NULL)
	{
		rootNode = CreateNewLeafNode(nodeValue);
	}

	// Check current node's left pointer  
	else if(nodeValue < ptr->nodeValue)
	{
		// If left child node is NOT empty
		if(ptr->leftChildNode != NULL)
		{
			// Recursively call the add function
			AddPrivateLeafNode(nodeValue, ptr->leftChildNode); 
		}
		else
		{
			ptr->leftChildNode = CreateNewLeafNode(nodeValue);
		}
	}

	// Check current node's right pointer
	else if(nodeValue > ptr->nodeValue)
	{
		// If left child node is NOT empty
		if(ptr->rightChildNode != NULL)
		{
			// Recursively call the add function
			AddPrivateLeafNode(nodeValue, ptr->rightChildNode); 
		}
		else
		{
			ptr->rightChildNode = CreateNewLeafNode(nodeValue);
		}

	}

	// Finally we catch duplicates
	else
	{
		cout << "\nThe key " << nodeValue << " has already been added to the tree!" << endl;	
	}	

}

// Getter for an in-order traversal function on the BST 
void BinarySearchTree::PrintInOrder()
{
	PrivatePrintInOrder(rootNode);
}

// In-order traversal of the BST
void BinarySearchTree::PrivatePrintInOrder(BinarySearchTreeNode* ptr)
{
	if(rootNode != NULL)
	{
		// Check if we can move left
		if(ptr->leftChildNode != NULL)
		{
			PrivatePrintInOrder(ptr->leftChildNode);
		}
		cout << ptr->nodeValue << " ";

		// Check if we can move right
		if(ptr->rightChildNode != NULL)
		{
			PrivatePrintInOrder(ptr->rightChildNode);	
		}
	}
	else
	{
		cout << "\nError: Traversal not possible. Tree is empty" << endl;
	}
}

// Getter for a function that returns a node based on given key-value, or node-value as its defined here
BinarySearchTree::BinarySearchTreeNode* BinarySearchTree::ReturnNodeFromKeyValue(int nodeValue)
{
	return PrivateReturnNodeFromKeyValue(nodeValue, rootNode);
}


BinarySearchTree::BinarySearchTreeNode* BinarySearchTree::PrivateReturnNodeFromKeyValue(int nodeValue, BinarySearchTreeNode* ptr)
{
	if(ptr != NULL)
	{
		// Return pointer pointing to the current node
		if(ptr->nodeValue == nodeValue)
		{
			return ptr;
		}
		else
		{
			if(nodeValue < ptr->nodeValue)
			{
				return PrivateReturnNodeFromKeyValue(nodeValue, ptr->leftChildNode);
			}
			else
			{
				return PrivateReturnNodeFromKeyValue(nodeValue, ptr->rightChildNode);
			}
		}	
	}
	else
	{
		return NULL;
	}
}

int BinarySearchTree::ReturnRootNodeValue()
{
	if(rootNode != NULL)
	{
		return rootNode->nodeValue;
	}
	else
	{
		return -999;
	}
}

// Prints all possible children of the target node
void BinarySearchTree::PrintChildrenOfCurrentNode(int nodeValue)
{
	BinarySearchTreeNode* ptr = ReturnNodeFromKeyValue(nodeValue);

	if(ptr != NULL)
	{
		cout << "Parent Node Value: " << ptr->nodeValue << endl;

		// Check left child
		ptr->leftChildNode == NULL ?
		cout << "Left child node value is NULL\n": cout << "Left Child node value is " << ptr->leftChildNode->nodeValue << endl;

		// Check right child
		ptr->rightChildNode == NULL ?
		cout << "Right child node value is NULL\n": cout << "Right Child node value is " << ptr->rightChildNode->nodeValue << endl;
	}
	else
	{
		cout << "\nNode Value: " << " was not found not in the tree.\n" << endl;
	}
}



// Getter function for private function below
int BinarySearchTree::FindSmallestNodeValueInTree()
{
	return PrivateFindSmallestNodeValueInTree(rootNode);
}


// Function that will recursively move through the tree to find the smallest value.
// Intuitively this means that the leftmost child of the leftmost subtree should be the
// smallest value in the tree since this follows the properties of a BST. 
int BinarySearchTree::PrivateFindSmallestNodeValueInTree(BinarySearchTreeNode* ptr)
{
	if(rootNode == NULL)
	{	
		cout << "\nError: The tree is empty" << endl;
		return -999;
	}
	else
	{
		if(ptr->leftChildNode != NULL)
		{
			return PrivateFindSmallestNodeValueInTree(ptr->leftChildNode);
		}
		else
		{
			return ptr->nodeValue;
		}
	}
}

// Getter function to remove a node from the BST
void BinarySearchTree::RemoveNode(int nodeValue)
{
	PrivateRemoveNode(nodeValue, rootNode);
}

// Recursively removes a node from the BST
void BinarySearchTree::PrivateRemoveNode(int nodeValue, BinarySearchTreeNode* parentNodePtr)
{
	if(rootNode != NULL)
	{
		if(rootNode->nodeValue == nodeValue)
		{
			RemoveRootMatch();
		}
		else
		{	// Check if the node we are looking for is less than the parent node's value 
			// AND its left child node's value, then
			if( nodeValue < parentNodePtr->nodeValue && parentNodePtr->leftChildNode != NULL )
			{
				// The parent's left child's key value matches the value we want to delete
				parentNodePtr->leftChildNode->nodeValue == nodeValue ?
				RemoveMatch(parentNodePtr, parentNodePtr->leftChildNode, true):
				PrivateRemoveNode(nodeValue, parentNodePtr->leftChildNode);
			}
			// Perform same check for the parent node's right child
			else if( nodeValue > parentNodePtr->nodeValue && parentNodePtr->rightChildNode != NULL )
			{
				// The parent's left child's key value matches the value we want to delete
				parentNodePtr->rightChildNode->nodeValue == nodeValue ?
				RemoveMatch(parentNodePtr, parentNodePtr->rightChildNode, false):
				PrivateRemoveNode(nodeValue, parentNodePtr->rightChildNode);
			}
			else
			{
				cout << "\nThe key " << nodeValue << " was not found in the tree. Cannot delete." << endl;
			}
		}
	}
	else
	{
		cout << "\nError: Cannot delete anything. The tree is empty" << endl;
	}
}

void BinarySearchTree::RemoveRootMatch()
{	
	
	// Check for non-empty tree
	if(rootNode != NULL)
	{
		BinarySearchTreeNode* deletePtr = rootNode;
		int rootNodeValue = rootNode->nodeValue;
		int smallestValueInRightSubtree;

		// Case 0 - Zero children
		if(rootNode->leftChildNode == NULL && rootNode->rightChildNode == NULL)
		{
			rootNode = NULL;
			delete deletePtr;
		}

		// Case 1 - Root node has one right child
		else if(rootNode->leftChildNode == NULL && rootNode->rightChildNode != NULL)
		{
			rootNode = rootNode->rightChildNode;
			deletePtr->rightChildNode = NULL;	// Sets right child to zero (disconnecting from tree)
			delete deletePtr;
			cout << "The root node with key " << rootNodeValue << " was deleted" 
			<< ". The new root is now contains key " << rootNode->nodeValue << endl; 
		}

		// Case 2- Root has one left child
		else if(rootNode->leftChildNode != NULL && rootNode->rightChildNode == NULL)
		{
			rootNode = rootNode->leftChildNode;
			deletePtr->leftChildNode = NULL;	// Sets right child to zero (disconnecting from tree)
			delete deletePtr;
			cout << "The root node with key " << rootNodeValue << " was deleted" 
			<< ". The new root is now contains key " << rootNode->nodeValue << endl; 
		}

		// Case 3 - Root node has both left and right children
		// Removes the smallest value in the root's right subtree
		// and preserves the format of the BST
		else
		{
			smallestValueInRightSubtree = PrivateFindSmallestNodeValueInTree(rootNode->rightChildNode);
			PrivateRemoveNode(smallestValueInRightSubtree, rootNode);
			rootNode->nodeValue = smallestValueInRightSubtree; 
			cout << "The root key containing " << rootNodeValue << " was overwritten with key " << rootNode->nodeValue << endl;

		}
	} 
	else
	{
		cout << "\nRemoveRoot() not working. Tree is empty." << endl;
	}
}

void BinarySearchTree::RemoveMatch(BinarySearchTreeNode* parentNodePtr, BinarySearchTreeNode* match, bool isLeftChild)
{
	if(rootNode != NULL)
	{
		BinarySearchTreeNode* deletePtr;
		int matchNodeValue = match->nodeValue;
		int smallestValueInRightSubtree;

		// Case 0 - Zero children
		if(match->leftChildNode == NULL && match->rightChildNode == NULL)
		{
			deletePtr = match;
			isLeftChild == true ? parentNodePtr->leftChildNode = NULL : parentNodePtr->rightChildNode = NULL;
			delete deletePtr;
			cout << "The node containing node value " << matchNodeValue << " was deleted.\n";

		}

		// Case 1 - 1 child
		else if(match->leftChildNode == NULL && match->rightChildNode != NULL)
		{
			isLeftChild == true ? parentNodePtr->leftChildNode = match->rightChildNode : parentNodePtr->rightChildNode = match->rightChildNode;
			match->rightChildNode = NULL;
			deletePtr = match;
			delete deletePtr;
			cout << "\nThe node containing node value " << matchNodeValue << " was deleted.\n";
		}
		else if(match->leftChildNode != NULL && match->rightChildNode != NULL)
		{
			isLeftChild == true ? parentNodePtr->leftChildNode = match->leftChildNode : parentNodePtr->rightChildNode = match->leftChildNode;
			match->leftChildNode = NULL;
			deletePtr = match;
			delete deletePtr;
			cout << "\nThe node containing node value " << matchNodeValue << " was deleted.\n";
		}
		// Case 2 - 2 children
		else
		{
			smallestValueInRightSubtree = PrivateFindSmallestNodeValueInTree(match->rightChildNode);
			PrivateRemoveNode(smallestValueInRightSubtree, match);
			match->nodeValue = smallestValueInRightSubtree;
		}


	}
	else
	{
		// Just in case the tree might be empty, for debugger purposes
		cout << "Cannot remove match. The tree is empty.\n";
	}
}

// Post-order traversal to delete all nodes in the given subtree 
void BinarySearchTree::RemoveSubtree(BinarySearchTreeNode* ptr)
{
	if(ptr != NULL)
	{
		if(ptr->leftChildNode != NULL)
		{
			RemoveSubtree(ptr->leftChildNode);
		}

		if(ptr->rightChildNode != NULL)
		{
			RemoveSubtree(ptr->rightChildNode);
		}
		cout << "\nDeleting node containing the value: " << ptr->nodeValue << endl;
		delete ptr;
	}
}