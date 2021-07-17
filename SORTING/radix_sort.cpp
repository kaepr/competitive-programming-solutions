#include <bits/stdc++.h>
using namespace std;

void radixSort(int arr[], int n, int exp) {
	int cnt[10] = {0};
	for (int i = 0; i < n; i++) {
		int dig = (arr[i] / exp) % 10;
		cnt[dig]++;
	}

	for (int i = 0; i < 10; i++) {
		cout << cnt[i] << " ";
	}
	cout << "\n";

	for (int i = 1; i < 10; i++) {
		cnt[i] = cnt[i] + cnt[i - 1];
	}

	for (int i = 0; i < 10; i++) {
		cout << cnt[i] << " ";
	}
	cout << "\n";

	int ans[n];
	for (int i = n - 1; i >= 0; i--) {
		int elm = arr[i];
		int dig = (arr[i] / exp) % 10;
		int index = cnt[dig] - 1;
		cnt[dig]--;
		ans[index] = elm;
	}

	for (int i = 0; i < n; i++) {
		arr[i] = ans[i];
	}
}

int main() {
	int n;
	cin >> n;
	int arr[n];
	int mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		mx = max(mx, arr[i]);
	}

	int exp = 1;
	while (exp < mx) {
		radixSort(arr, n, exp);
		exp *= 10;
	}

	cout << "Final\n";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}