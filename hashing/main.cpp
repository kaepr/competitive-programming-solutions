#include <bits/stdc++.h>
using namespace std;

int tripletsInGb(vector<int> a, int r) {
	map<int, int> mp_left, mp_right;

	int n = a.size();
	for (int i = 0; i < n; i++) {
		mp_right[a[i]]++;
	}

	mp_right[a[0]]--;
	mp_left[a[0]]++;

	int ans = 0;
	for (int i = 1; i < n - 1; i++) {
		int nxt = a[i] * r;
		if (a[i] % r != 0) {
			mp_right[a[i]]--;
			mp_left[a[i]]++;
			continue;
		}
		int prev = a[i] / r;

		ans += mp_right[nxt] * mp_left[prev];
		mp_right[a[i]]--;
		mp_left[a[i]]++;
	}

	return ans;

}

void solve() {
	vector<int> a = {1, 16, 4, 16, 64, 16};
	cout << tripletsInGb(a, 4);
}

int main() {
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 1;
	// cin >> t;
	while (t > 0)
	{
		solve();
		t--;
	}

	return 0;
}
