#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> stringSearch(string big, string small) {
	//store the occurrences in the result vector
	vector<int> result = {};
	int index = big.find(small);

	while (index != -1) {
		result.push_back(index);
		index = big.find(small, index + 1);
	}

	return result;
}


// void tokenizing() {
// 	string input;
// 	getline(cin, input);
// 	stringstream ss(input);

// 	string token;
// 	vector<string> t

// }



void subsequence(string s, string o, vector<string> &v) {
	if (s.size() == 0) {
		v.push_back(o);
		return;
	}

	char ch = s[0];
	string reduced_input = s.substr(1);
	subsequence(reduced_input, o + ch, v);
	subsequence(reduced_input, o, v);
}


int main() {
	string s;
	cin >> s;
	vector<string> v;
	string output = "";
	subsequence(s, output, v);
	sort(v.begin(), v.end(), [&](auto s1, auto s2) {
		if (s1.length() == s2.length()) {
			return s1 < s2;
		}
		return s1.length() < s2.length();
	});

	for (auto x : v) {
		cout << x << "\n";
	}
	// tokenizing();
	// int t = 1;
	// cin >> t;
	// auto x = stringSearch("hello hello hello", "hello");

	// for (auto y : x) {
	// 	cout << y << " ";
	// }

	return 0;

}