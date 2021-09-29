#include <bits/stdc++.h>
using namespace std;

/*
Complete Binary tree
Filled completetly from
Top to bottom, and then
left to right
*/


class MinHeap {
	int *arr;
	int size;
	int capacity;

public:
	MinHeap(int c) {
		size = 0;
		capacity = c;
		arr = new int[c];
	}

	int left(int i) {
		return 2 * i + 1;
	}

	int right(int i) {
		return 2 * i + 2;
	}

	int parent(int i) {
		return (i - 1) / 2;
	}

	void insert(int x) {
		if (size == capacity) {
			return;
		}

		size++;
		arr[size - 1] = x;

		// Check if parent is bigger element ( or root condition )
		// If parent is bigger, then swap with current
		// and change index to be the parent
		for (int i = size - 1; i != 0 && arr[parent(i)] > arr[i]) {
			swap(arr[i], arr[parent(i)]);
			i = parent(i);
		}
	}

	void minHeapify(int i) {
		int lt = left(i);
		int rt = right(i);
		int smallest = i;

		// Checks added to handle if left child exists or not
		if (lt < size && arr[lt] < arr[i]) {
			smallest = lt;
		}

		// Checks added to handle if right child exists or not
		if (rt < size && arr[rt] < arr[smallest]) {
			smallest = rt;
		}

		// smallest now contains the node which is the smallest
		if (smallest != i) {
			swap(arr[i], arr[smallest]);
			minHeapify(smallest);
		}
	}

	int extractMin() {
		if (size <= 0) {
			return INT_MAX;
		}

		if (size == 1) {
			size--;
			return arr[0];
		}

		swap(arr[0], arr[size - 1]);
		size--;
		minHeapify(0);

		return arr[size];
	}

	void decreaseKey(int i, int x) {
		arr[i] = x;
		while (i != 0 && arr[parent(i)] > arr[i]) {
			swap(arr[i], arr[parent(i)]);
			i = parent(i);
		}
	}

	void deleteKey(int i) {
		decreaseKey(i, INT_MIN);
		extractMin();
	}

	void buildHeap() {
		for (int i = (size - 2) / 2; i >= 0; i--) {
			minHeapify(i);
		}
	}
};


// Used for max heapify
void heapify(int arr[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void buildheap(int arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
}
void heapSort(int arr[], int n)
{
	buildheap(arr, n);

	for (int i = n - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

int main() {
	int arr[] = {12, 11, 13, 5, 6, 7};
	int n = sizeof(arr) / sizeof(arr[0]);

	heapSort(arr, n);

	cout << "Sorted array is \n";
	printArray(arr, n);
	return 0;
}