#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll MOD = 1e9 + 7;

int countSubsetsEqualToX(vector<int> &arr, int n, int i, int X) {
	if (i == n) {
		if (X == 0) {
			return 1;
		}
		return 0;
	}

	int inc = countSubsetsEqualToX(arr, n, i + 1, X - arr[i]);
	int exc = countSubsetsEqualToX(arr, n, i + 1, X);
	return inc + exc;
}


// string s = "abcd";
// vector<string> v;

// for (int idx = 0; idx < s.length(); idx ++) {
// 	string tmp = "";
// 	for (int j = idx; j < s.length(); j++) {
// 		tmp += s[j];
// 		v.push_back(tmp);
// 	}
// }

// for (auto x : v) {
// 	cout << x << "\n";
// }

// int sol() {


// 	int curr = 0;
// 	int elems = 0;
// 	int ptr = 0;

// 	int n = v.size();

// 	int ans = curr;

// deque<int> q;
// while (ptr < n) {
// 	// if it increases current sum
// 	if (curr + v[ptr] >= 0) {
// 		// if window is less than k
// 		if (q.size() < k) {
// 			// take it
// 			q.push_back(v[ptr]);
// 			curr += v[ptr];
// 		} else {
// 			// remove the last one
// 			int to_remove = q.front();
// 			q.pop_front();
// 			curr -= to_remove;
// 			curr += v[ptr];
// 		}

// 		ans = max(ans, curr);
// 		ptr++;
// 	} else {

// 		}

// 		return ans;
// 	}
// }


long max_subarray_of_k(vector<int> &arr, int k, int n) {

	long res = 0;
	for (int i = 0; i < k; i++)
		res += arr[i];

	long curr_sum = res;
	for (int i = k; i < n; i++) {
		curr_sum += arr[i] - arr[i - k];
		res = max(res, curr_sum);
	}

	return res;
}

long main2(vector<int> &arr, int n, int k) {
	long ans = 0;

	for (int i = 1; i <= k; i++) {
		long cur = max_subarray_of_k(arr, i, n);
		ans = max(ans, cur);
	}

	return ans;
}


long mainSol(vector<int> arr, int n, int k) {
	vector<long> neg_sum(n, 0);

	long curr = 0;

	reverse(arr.begin(), arr.end());

	for (int i = 0; i < n; i++) {
		int idx = i;
		int val = arr[i];
		neg_sum[idx] = curr;
		curr += val;

		if (curr > 0) {
			curr = 0;
		}
	}

	reverse(neg_sum.begin(), neg_sum.end());

	int i = 0, j = 0;
	long ans = 0;
	long cur = 0;

	while (j < n) {
		cur += arr[j];
		if (cur + neg_sum[j] <= k) {

		}
	}

	return 0;
}

int main() {
	vector<int> v = {5, -7, 8, -6, 4, 1, -9, 5};
	int k = 2;
	int n = v.size();
	mainSol(v, n, k);
	cout << main2(v, v.size(), k) << "\n";
	return 0;
}
