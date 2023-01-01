#include <bits/stdc++.h>
using namespace std;

void cycleSortDistinct(int arr[], int n) {
	for (int cs = 0; cs < n - 1; cs++) {
		int item = arr[cs], pos = cs;
		for (int i = cs + 1; i < n; i++) {
			if (arr[i] < item) {
				pos++;
			}
		}
		swap(item, arr[pos]);
		while (pos != cs) {
			pos = cs;
			for (int i = cs + 1; i < n; i++) {
				if (arr[i] < item) {
					pos++;
				}
			}
			swap(item, arr[pos]);
		}
	}
}

void cycleSort(int arr[], int n) {
	int writes = 0;
	for (int cs = 0; cs < n - 1; cs++) {
		int item = arr[cs];
		int pos = cs;
		for (int i = cs + 1; i < n; i++) {
			if (arr[i] < item) {
				pos++;
			}
		}

		if (pos == cs) {
			// already at correct position
			continue;
		}

		while (item == arr[pos]) {
			pos++;
		}

		if (pos != cs) {
			swap(arr[pos], item);
			writes++;
		}

		for (int j = 0; j < n; j++) {
			cout << arr[j] << " ";
		}
		cout << "\n";

		while (pos != cs) {
			pos = cs;
			for (int i = cs + 1; i < n; i++) {
				if (arr[i] < item) {
					pos++;
				}
			}

			while (item == arr[pos]) {
				pos++;
			}

			if (item != arr[pos]) {
				writes++;
				swap(arr[pos], item);

			}

			for (int j = 0; j < n; j++) {
				cout << arr[j] << " ";
			}
			cout << "\n";
		}
	}
	for (int j = 0; j < n; j++) {
		cout << arr[j] << " ";
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

	// cycleSortDistinct(arr, n);
	cycleSort(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}