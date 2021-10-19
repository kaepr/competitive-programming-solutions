#include <bits/stdc++.h>
using namespace std;

string s = "abcde";
string words[] = {"a", "b", "abcde"};

int min_bars_helper(string s, string words[], int idx, unordered_set<string> &m) {
	if (s[idx] == '\0') {
		return 0;
	}

	int ans = INT_MAX;
	string current_string = "";

	for (int j = idx; s[j] != '\0'; j++) {
		current_string += s[j];

		if (m.find(current_string) != m.end()) {
			int rem_ans = min_bars_helper(s, words, j + 1, m);
			if (rem_ans != -1) {
				ans = min(ans, 1 + rem_ans);
			}
		}
	}

	if (ans == INT_MAX) {
		return -1;
	}
	return ans;
}

int min_bars() {
	unordered_set<string> m;
	for (string w : words) {
		m.insert(w);
	}

	int output = min_bars_helper(s, words, 0, m);
	return output;
}

void solve() {
	cout << min_bars() - 1 << "\n";
}

int main() {
	solve();
	return 0;
}