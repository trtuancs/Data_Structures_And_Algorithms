#include<ctime>
#include <chrono>
#include<random>
#include"InsertionSort.h"
#include"HeapSort.h"
#include"MergeSort.h"
#include<iostream>
using namespace std;

void print(int* a, int size) {
	for (int i = 0; i < size; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main() {
	srand(time(NULL));
	int n = 10;
	int* a = new int[n];

	//Problem 01
	cout << "Problem 01\n";
	for (int i = 0; i < n; i++) a[i] = rand() % (10*n);
	print(a, n);
	InsertionSort(a, n);
	print(a, n);

	//Problem 02
	cout << "\nProblem 02\n";
	for (int i = 0; i < n; i++) a[i] = rand() % (10 * n);
	print(a, n);
	HeapSort(a, n);
	print(a, n);

	//Problem 03
	cout << "\nProblem 03\n";
	for (int i = 0; i < n; i++) a[i] = rand() % (10 * n);
	print(a, n);
	MergeSort(a, n);
	print(a, n);

	delete[] a;
	return 0;
}






