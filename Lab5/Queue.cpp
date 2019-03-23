#include"Queue.h"


template <class T>
void Queue<T>::clear() {
	QueueNode<T> *p;
	while (p = front) {
		front = front->link;
		delete[] p;
	}
	front = rear = NULL;
	count = 0;
}

template <class T>
void Queue<T>::print2Console() {
	QueueNode<T>* p = front;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->link;
	}

}

template <class T>
void Queue<T>::enQueue(T val) {
	QueueNode<T> *pNew = new QueueNode<T>(val);
	if (count == 0) {
		front = pNew;
		rear = pNew;
	}
	else {
		rear->link = pNew;
		rear = pNew;
	}
	count++;
}

template <class T>
int Queue<T>::deQueue(T &valOut) {
	if (count == 0) return 0;
	QueueNode<T>* p = front;
	valOut = front->data;
	front = front->link;
	delete p;
	count--;
	if (count == 0) rear = NULL;
	return 1;
}