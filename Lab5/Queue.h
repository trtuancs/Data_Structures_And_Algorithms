#include<iostream>
using namespace std;
template <class T>
class QueueNode{
public:
	T data;
	QueueNode* link;

	QueueNode(T val) {
		data = val;
		link = NULL;
	}
};

template <class T>
class Queue {
private:
	QueueNode<T>* front;
	QueueNode<T>* rear;
	int count;
public:
	Queue() {
		front = rear = NULL;
		count = 0;
	}
	~Queue() {
		clear();
	}
	void clear();
	void enQueue(T val);
	void print2Console();
	int deQueue(T& valOUt);
};

