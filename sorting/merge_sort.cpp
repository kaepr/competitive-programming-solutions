#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int left_half[n1], right_half[n2];
	for (int i = 0; i < n1; i++) {
		left_half[i] = arr[left + i];
	}

	for (int i = 0; i < n2; i++) {
		right_half[i] = arr[mid + 1 + i];
	}

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (left_half[i] <= right_half[j]) {
			arr[k] = left_half[i];
			i++;
			k++;
		} else {
			arr[k] = right_half[j];
			j++;
			k++;
		}
	}

	while (i < n1) {
		arr[k] = left_half[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = right_half[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int left, int right) {
	if (right > left) {
		int mid = left + (right - left) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

int countMerge(int arr[], int l, int m, int r) {
	int n1 = m - l + 1, n2 = r - m, res = 0;
	int left[n1], right[n2];

	for (int i = 0; i < n1; i++) {
		left[i] = arr[l + i];
	}
	for (int i = 0; i < n2; i++) {
		right[i] = arr[m + 1 + i];
	}

	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2) {
		if (left[i] <= right[j]) {
			arr[k] = left[i];
			i++;
			k++;
		} else {
			arr[k] = right[j];
			j++;
			k++;
			res += (n1 - i);
		}
	}

	while (i < n1) {
		arr[k] = left[i];
		k++;
		i++;
	}

	while (j < n2) {
		arr[k] = right[j];
		j++;
		k++;
	}

	return res;
}

int countInv(int arr[], int left, int right) {
	int res = 0;
	if (right > left) {
		int mid = left + (right - left) / 2;
		res += countInv(arr, left, mid);
		res += countInv(arr, mid + 1, right);
		res += countMerge(arr, left, mid, right);
	}
	return res;
}


int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << countInv(arr, 0, n - 1) << "\n";

	mergeSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}



	return 0;
}