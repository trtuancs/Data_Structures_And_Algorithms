#include"BinaryTree.h"

int main() {
	BinaryTree tree1;
	tree1.buildTree();
	BinaryTree tree2;
	int a[] = { 3, 6, 4, 8, 9, 7, 2, 1 };
	for (int i = 0; i < 8; i++)
		tree2.addBST(a[i]);

	
	
	// Problem 01
	cout << "Problem 01" << endl;
	tree1.printTreeStructure();
	cout << "The number of nodes with two children: " << tree1.countTwoChildrenNodes() << endl;
	cout << endl;

	// Problem 02
	cout << "Problem 02" << endl;
	tree1.printTreeStructure();
	cout << "The breadth first search traversal: ";
	tree1.printBreadthFirstSearch();
	cout << endl<<endl;

	// Problem 03
	cout << "Problem 03" << endl;
	tree1.printTreeStructure();
	cout << "Tree 1 is BST: " << tree1.isBST() << endl;
	tree2.printTreeStructure();
	cout << "Tree 2 is BST: " << tree2.isBST() << endl;
	return 0;
}












