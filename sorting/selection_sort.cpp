#include <bits/stdc++.h>
using namespace std;


// Selection Sort
void selectionSort(int arr[], int n) {

	for (int i = 0; i < n - 1; i++) {
		int cur_min_index = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[cur_min_index]) {
				cur_min_index = j;
			}
		}
		swap(arr[cur_min_index], arr[i]);
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

	selectionSort(arr, n);

	return 0;
}