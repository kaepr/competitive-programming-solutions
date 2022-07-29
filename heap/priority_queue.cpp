#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll MOD = 1e9 + 7;

class Compare {
public:
	bool operator()(int a, int b) {
		return a > b;
	}
};

int main() {
	int arr[] = {10, 15, 20, 13, 6, 90};
	int n = sizeof(arr) / sizeof(int);

	// default is max heap
	priority_queue<int> heap;

	for (auto x : arr) {
		heap.push(x);
	}


	// min heap
	priority_queue<int, vector<int>, greater<int>> heap2;

	// custom comparator
	priority_queue<int, vector<int>, Compare> heap3;

	return 0;
}
