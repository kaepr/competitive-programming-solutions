#include <bits/stdc++.h>
using namespace std;


// Insertion Sort
void insertionSort(int arr[], int n) {

	for (int i = 1; i < n; i++) {
		int j = i - 1;
		int key = arr[i];
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

int main() {

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	insertionSort(arr, n);

	return 0;
}