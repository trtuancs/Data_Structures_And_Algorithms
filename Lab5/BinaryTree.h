#include"Node.h"
class BinaryTree
{
private:
	Node * root;
	int size;
protected:
	void clearRecursion(Node*root);
	int getHeightRecursion(Node*root);
	void printInOrderRecursion(Node*root);
	void printPreOrderRecursion(Node*root);
	void addBSTRecursion(Node*& root, int val);
	int deleteBSTRecursion(Node*& root, int val);


public:
	BinaryTree();
	~BinaryTree();
	void buildTree();
	void clear();
	void printPreOrder();
	void printInOrder();
	void addBST(int val);
	int getHeight();
	int deleteBST(int val);
	void printTreeStructure();

	//Problem 01
	int countTwoChildrenNodes();

	//Problem 02
	void printBreadthFirstSearch();

	//Problem 03
	bool isBST();
};

