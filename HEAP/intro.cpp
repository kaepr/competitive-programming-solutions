#include <bits/stdc++.h>
using namespace std;



/*


Priority Queue
A structure which implements a set S of elements each of elements has a key associated with it

for eg {(x,k)}

Operations allowed :
insert(S,x): insert element x into set S
max(S) returns element of S with the largest key
extract_max(S): returns and pops the largest key
increase_key(S,x,k): increase the specified x


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
		for (int i = size - 1; i != 0 && (arr[parent(i)] > arr[i]);) {
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

	//  Its O(n) in complexity, as the amount of times get called for log(n) times
	// Is only the final root of the tree
	// Rest of the times, the amount of times heapify being is called is less
	// Thus asymptotically its actually O(n)
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
	// First build the heap
	buildheap(arr, n);

	// Keep swapping highest element with last
	// Then decrease array size
	// Then as there is just one violation,
	// Call heapify on it
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

class Compare {
public:
	bool operator()(int a, int b) {
		return a > b;
	}
};

class MedianFinder {
public:
	priority_queue<int> p1; // max heap
	priority_queue<int, vector<int>, greater<int>> p2; // min heap

	MedianFinder() {
		// p1.clear();
		// p2.clear();
	}

	void addNum(int num) {
		if (p1.empty() ||  p1.top() > num) {
			p1.push(num);
		} else {
			p2.push(num);
		}

		if (p1.size() > p2.size() + 1) {
			p2.push(p1.top());
			p1.pop();
		} else if (p2.size() > p1.size() + 1) {
			p1.push(p2.top());
			p2.pop();
		}
	}

	double findMedian() {
		if (p1.size() == p2.size()) {
			int x = p1.top();
			int y = p2.top();
			return (x * 1.0 + y * 1.0) / (2 * 1.0);
		} else {
			if (p1.size() > p2.size()) {
				return p1.top();
			} else {
				return p2.top();
			}
		}
	}
};

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class myComparator {
public:
	int operator()(ListNode* p1, ListNode* p2) {
		return p1->val > p2->val;
	}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<ListNode*, vector<ListNode*>, myComparator> pq;

		for (int i = 0; i < lists.size(); i++) {
			if (lists[i]) {
				pq.push(lists[i]);
			}
		}

		ListNode *ptr, *h, *tmp;
		ptr = new ListNode();
		head = ptr;
		while (pq.size()) {
			if (pq.top() != NULL) {
				ptr->next = new ListNode(pq.top()->val);
				ptr = ptr->next;
				tmp = pq.top();
				pq.pop();

				if (tmp->next) {
					pq.push(tmp->next);
				}
			} else {
				pq.pop();
			}
			ptr -> next = NULL;
		}
		return head->next;
	}
};

int main() {
	// int arr[] = {12, 11, 13, 5, 6, 7};
	// int n = sizeof(arr) / sizeof(arr[0]);

	// heapSort(arr, n);

	// cout << "Sorted array is \n";
	// printArray(arr, n);

	int arr[] = {10, 15, 20, 13, 6, 90};
	int n = sizeof(arr) / sizeof(int);
	priority_queue <int, vector<int>, Compare> heap;

	for (int x : arr) {
		heap.push(x);
	}

	while (!heap.empty()) {
		cout << heap.top() << " ";
		heap.pop();
	}




	return 0;
}