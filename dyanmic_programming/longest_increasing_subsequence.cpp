#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll MOD = 1e9 + 7;

int lis(vector<int> const& a) {
	int n = a.size();
	vector<int> d(n, 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i])
				d[i] = max(d[i], d[j] + 1);
		}
	}

	int ans = d[0];
	for (int i = 1; i < n; i++) {
		ans = max(ans, d[i]);
	}
	return ans;
}

/*

p[i] will be the index j of the second last element
in LIS ending in i

*/


vector<int> lisPos(vector<int> a) {
	int n = a.size();
	vector<int> d(n, 1), p(n, -1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] and d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
				p[i] = j;
			}
		}
	}

	int ans = d[0], pos = 0;
	for (int i = 1; i < n; i++) {
		if (d[i] > ans) {
			ans = d[i];
			pos = i;
		}
	}

	vector<int> subseq;
	while (pos != -1) {
		subseq.push_back(a[pos]);
		pos = p[pos];
	}
	reverse(subseq.begin(), subseq.end());
	return subseq;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	return 0;
}
