#include "BinaryTree.h"
#include"Queue.cpp"
#include <iomanip>  

void printNSpace(int n) {
	for (int i = 0; i < n-1; i++) cout << " ";
}

BinaryTree::BinaryTree()
{
	root == NULL;
	size = 0;
}


BinaryTree::~BinaryTree()
{
	clear();
}

void BinaryTree::clearRecursion(Node* root) {
	if (root != NULL) {
		clearRecursion(root->left);
		clearRecursion(root->right);
		delete root;
	}
}
void BinaryTree::clear() {
	clearRecursion(root);
}
void BinaryTree::buildTree() {
	root = new Node(3);
	root->left = new Node(6);
	root->right = new Node(4);
	root->left->left = new Node(8);
	root->left->right = new Node(9);
	root->left->right->right = new Node(2);	
	root->right->right = new Node(7);
	root->right->right->left = new Node(1);
}

void BinaryTree::printPreOrderRecursion(Node* root) {
	if (root != NULL) {
		cout << root->data << " ";
		printPreOrderRecursion(root->left);
		printPreOrderRecursion(root->right);
	}
}

void BinaryTree::printPreOrder() {
	cout << "The preorder traversal is: ";
	printPreOrderRecursion(root);
	cout << endl;
}

void BinaryTree::printInOrderRecursion(Node* root) {
	if (root != NULL) {		
		printInOrderRecursion(root->left);
		cout << root->data << " ";
		printInOrderRecursion(root->right);
	}
}

void BinaryTree::printInOrder() {
	cout << "The inorder traversal is: ";
	printInOrderRecursion(root);
	cout << endl;
}

int BinaryTree::getHeightRecursion(Node* root) {
	if (root == NULL) return 0;
	int lh = getHeightRecursion(root->left);
	int rh = getHeightRecursion(root->right);
	return (lh > rh ? lh : rh) + 1;
}

int BinaryTree::getHeight() {
	return getHeightRecursion(root);
}

void BinaryTree::printTreeStructure() {
	int height = getHeight();

	if (root == NULL) {
		cout << "NULL\n";
		return;
	}
	Queue<Node*> q;
	q.enQueue(root);
	Node* temp;
	int count = 0;
	int maxNode = 1;
	int level = 0;
	int space = pow(2, height);
	printNSpace(space / 2);
	while (q.deQueue(temp)) {
		
		if (temp == NULL) {
			cout << " ";
			q.enQueue(NULL);
			q.enQueue(NULL);
		}
		else {
			
			cout << temp->data;
			q.enQueue(temp->left);
			q.enQueue(temp->right);
		}
		printNSpace(space);
		count++;
		if (count == maxNode) {
			cout << endl;
			count = 0;
			maxNode *= 2;
			level++;
			space /= 2;
			printNSpace(space / 2);
		}		
		if (level == height) return;
	}
}


void BinaryTree::addBSTRecursion(Node*& root, int val) {
	if (root == NULL) 
		root = new Node(val);
	else {
		if (val > root->data)
			addBSTRecursion(root->right, val);
		else
			addBSTRecursion(root->left, val);
	}
}

void BinaryTree::addBST(int val) {
	addBSTRecursion(root, val);
}


int BinaryTree::deleteBSTRecursion(Node*& root, int val) {
	if (root == NULL)
		return false;
	else if (root->data > val)
		return deleteBSTRecursion(root->left, val);
	else if (root->data < val)
		return deleteBSTRecursion(root->right, val);
	else {
		if (root->left == NULL) {
			Node* p = root;
			root = root->right;
			delete p;
			return true;
		}
		else if (root->right == NULL) {
			Node* p = root;
			root = root->left;
			delete p;
			return true;
		}
		else {
			Node* p = root->left;
			while (p->right) p = p->right;
			root->data = p->data;
			return deleteBSTRecursion(root->left, p->data);
		}
	}
}

int BinaryTree::deleteBST(int val) {
	return deleteBSTRecursion(root, val);
}

int BinaryTree::countTwoChildrenNodes() {
	// Problem 01 - TODO
}




void BinaryTree::printBreadthFirstSearch() {
	// Problem 02- TODO
}

bool BinaryTree::isBST() {
	// Problem 03 - TODO
}

