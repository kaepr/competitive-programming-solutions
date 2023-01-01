#include <bits/stdc++.h>
using namespace std;

void countSort(int arr[], int n) {
	int mx = arr[0], mn = arr[0];
	for (int i = 0; i < n; i++) {
		mx = max(mx, arr[i]);
		mn = min(mn, arr[i]);
	}
	int range = mx - mn + 1;
	cout << range << "\n";
	int cnt[range];
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; i++) {
		cnt[arr[i] - mn]++;
	}

	for (int i = 0; i < range; i++) {
		cout << cnt[i] << " ";
	}
	cout << "\n";

	for (int i = 1; i < range; i++) {
		cnt[i] = cnt[i] + cnt[i - 1];
	}

	for (int i = 0; i < range; i++) {
		cout << cnt[i] << " ";
	}
	cout << "\n";
	int ans[n];
	for (int i = n - 1; i >= 0; i--) {
		int elm = arr[i];
		int index = cnt[elm - mn] - 1;
		ans[index] = elm;
		cnt[elm - mn]--;
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
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

	countSort(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}