
// Here we declare the BST node as a class
// with all necessary functions/data
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

class BinarySearchTree
{
	private:

		struct BinarySearchTreeNode
		{
			int nodeValue;
			//BinarySearchTreeNode* parentNode;
			BinarySearchTreeNode* leftChildNode;
			BinarySearchTreeNode* rightChildNode;
		}; 

		BinarySearchTreeNode* rootNode;

		void 					AddPrivateLeafNode(int nodeValue, BinarySearchTreeNode* ptr);
		void 					PrivatePrintInOrder(BinarySearchTreeNode* ptr);
		BinarySearchTreeNode* 	PrivateReturnNodeFromKeyValue(int nodeValue, BinarySearchTreeNode* ptr);
		int 					PrivateFindSmallestNodeValueInTree(BinarySearchTreeNode* ptr);
		void 					PrivateRemoveNode(int nodeValue, BinarySearchTreeNode* parentNodePtr);
		void 					RemoveRootMatch();
		void					RemoveMatch(BinarySearchTreeNode* parentNodePtr, BinarySearchTreeNode* match, bool isLeftChild);
		BinarySearchTreeNode* 	CreateNewLeafNode(int nodeValue);
		BinarySearchTreeNode* 	ReturnNodeFromKeyValue(int nodeValue);
		void 					RemoveSubtree(BinarySearchTreeNode* ptr);

	public:	

		BinarySearchTree();
		~BinarySearchTree();
		void 					AddLeafNode(int nodeValue);
		void 					PrintInOrder();
		int 					ReturnRootNodeValue();
		void 					PrintChildrenOfCurrentNode(int nodeValue);
		int 					FindSmallestNodeValueInTree();
		void 					RemoveNode(int nodeValue);

};

#endif 