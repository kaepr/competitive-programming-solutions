#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll MOD = 1e9 + 7;

/*

Operations supported

initial construction takes O(N) time

push O(logN)
pop O(logN) removes the min/max element
top O(1) gets the min / max element

---> Heap is always a binary tree

---> Heap is a complete binary tree, all levels should be filled except last level
but it must be filled in left to Right

---> Heap must follow an order. For max heap, each parent >= it's children

Heaps represented as arrays

*/

class Heap {
private:
	vector<int> v;

	void heapify(int i) {
		int left = 2 * i;
		int right = 2 * i + 1;

		int minIdx = i;
		if (left < v.size() and v[left] < v[i]) {
			minIdx = left;
		}

		if (right < v.size() and v[right] < v[minIdx]) {
			minIdx = right;
		}

		if (minIdx != i) {
			swap(v[i], v[minIdx]);
			heapify(minIdx);
		}

	}

public:
	Heap(int default_size = 10) {
		v.reserve(default_size + 1);
		v.push_back(-1);
	}

	void push(int data) {
		// add data end to the heap
		v.push_back(data);
		int idx = v.size() - 1;
		int parent = idx / 2;
		while (idx > 1 and v[idx] < v[parent]) {
			swap(v[idx], v[parent]);
			idx = parent;
			parent = parent / 2;
		}
	}

	int top() {
		return v[1];
	}

	/**
	 * Swap v[1] and v[last] O(1)
	 * Remove the last element O(1)
	 * Heapify ( to fix the swap made in the first step ) O(logN)
	 * */
	void pop() {
		swap(v[1], v[v.size() - 1]);
		v.pop_back();
		heapify(1);
	}

	bool isEmpty() {
		return v.size() == 1;
	}
};

int main() {



	return 0;
}











