#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll MOD = 1e9 + 7;

// counting frequency of an element
int first_occurence(vector<int> arr, int key) {
	int s = 0, e = arr.size() - 1;
	int ans = -1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (arr[mid] == key) {
			ans = mid;
			e = mid - 1;
		} else if (arr[mid] > key) {
			e = mid - 1;
		} else {
			e = mid + 1;
		}
	}

	return ans;
}

int last_occurence(vector<int> arr, int key) {
	int s = 0, e = arr.size() - 1;
	int ans = -1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (arr[mid] == key) {
			ans = mid;
			s = mid + 1;
		} else if (arr[mid] > key) {
			e = mid - 1;
		} else {
			e = mid + 1;
		}
	}

	return ans;
}


// find square root using binary search
float square_root(int N, int P)  {
	int s = 0;
	int e = N;
	float ans = 0;

	while (s <= e) {
		int mid = (s + e) / 2;
		if (mid * mid == N) {
			return mid;
		} else if (mid * mid < N) {
			ans = mid;
			s = mid + 1;
		} else {
			e = mid - 1;
		}
	}

	// linear search for floating part
	float inc = 0.1;
	for (int place = 1; place <= P; place++) {

		while (ans * ans <= N) {
			ans += inc;
		}

		ans = ans - inc; // to get back correct value
		inc = inc / 10;
	}

	return ans;
}


void min_pair(vector<int> a1, vector<int> a2) {
	sort(a2.begin(), a2.end());

	int diff = INT_MAX;
	for (auto x : a1) {
		auto lb = lower_bound(a2.begin(), a2.end(), x) - a2.begin();

		if (lb >= 1 and x - a2[lb - 1] < diff) {
			diff = x - a2[lb - 1];
		}

		if (lb != a2.size() and a2[lb] - x < diff) {
			diff = a2[lb] - x;
		}
	}

	cout << diff << "\n";
}

bool divideAmongK(int arr[], int n, int k, int limit) {
	//return true if every partition gets atleast limit no of coins

	int cnt = 0;
	int current_sum = 0;

	for (int i = 0; i < n; i++) {
		if (current_sum + arr[i] >= limit) {
			cnt += 1;
			current_sum = 0;
		}
		else {
			current_sum += arr[i];
		}
	}

	return cnt >= k;
}

int k_partition(int arr[], int n, int k) {

	int e = 0;
	int s = 0;
	for (int i = 0; i < n; i++) {
		e += arr[i];
	}
	//mid
	int mid;
	int ans;
	//search range (s,e)
	while (s <= e) {
		mid = (s + e) / 2;

		bool isPossible = divideAmongK(arr, n, k, mid);

		if (isPossible) {
			s = mid + 1;
			ans = mid;
		}
		else {
			e = mid - 1;
		}
	}
	return ans;

}

int main() {
	cout << square_root(50, 3) << "\n";
	return 0;
}











