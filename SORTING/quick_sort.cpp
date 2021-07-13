#include <bits/stdc++.h>
using namespace std;


// Naive partition
void partition(int arr[], int l, int h, int p) {
	int temp[h - l + 1], index = 0;
	for (int i = l; i <= h; i++) {
		if (arr[i] <= arr[p] && i != p) {
			temp[index] = arr[i];
			index++;
		}
	}
	temp[index] = arr[p];
	index++;
	for (int i = l; i <= h; i++) {
		if (arr[i] > arr[p]) {
			temp[index] = arr[i];
			index++;
		}
	}
	for (int i = l; i <= h; i++) {
		arr[i] = temp[i - l];
	}
}


// Lomuto Partition
int lomutoPartition(int arr[], int left, int right) {
	int pivot = arr[right], i = left - 1;
	for (int j = left; j <= right - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(arr[j], arr[i]);
		}
	}
	swap(arr[i + 1], arr[right]);
	return i + 1;
}

// Hoare Partition
int hoarePartition(int arr[], int l, int h) {
	int pivot = arr[l];
	int i = l - 1, j = h + 1;
	while (true) {
		do {
			i++;
		} while (arr[i] < pivot);

		do {
			j--;
		} while (arr[j] > pivot);

		if (i >= j) {
			return j;
		}

		swap(arr[i], arr[j]);
	}
}

void quickSortLomuto(int arr[], int l, int h) {
	if (l < h) {
		int p = lomutoPartition(arr, l, h);
		quickSortLomuto(arr, l, p - 1);
		quickSortLomuto(arr, p + 1, h);
	}
}

void quickSortHoare(int arr[], int l, int h) {
	if (l < h) {
		int p = hoarePartition(arr, l, h);
		quickSortLomuto(arr, l, p);
		quickSortHoare(arr, p + 1, h);
	}
}




int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// quickSortLomuto(arr, 0, n - 1);
	quickSortHoare(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}