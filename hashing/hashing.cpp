#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll MOD = 1e9 + 7;

/*

Key components of hashing
--> Hash Function
--> Hash Table
--> Collision Handling Scheme

Operations supported
--> Insert
--> Search
--> Delete

Good Hash function properties
--> Reduce chance of collision - distribute keys uniformly over the table
--> should be fast to compute

Table Size should be prime number

Example: Hash function for strings
	Take weighted sum
	use all N characters of string as N digit base K number
	Recommended to use K to be a prime number > 26

//////////////////////////////////////////////////////////////////////////////

Separate Chaining
Open hashing
Use linked lists to store extra nodes if collision happens

*/

////////////////////////////////////////////////////////////////////////////////
// Counting total number of anagrams in a string


// generate all sustrings
// get ther hash value
// add the hash value to a frequency map
// count the total number of pairs possible

vector<int> getHashValue(string s, int i, int j) {
	vector<int> freq(26, 0);
	for (int k = i; k <= j; k++) {
		freq[s[k] - 'a']++;
	}

	return freq;
}

int total_anagram_substrings(string s) {
	map<vector<int>, int> mp;

	for (int i = 0; i < s.length(); i++) {
		for (int j = i; j < s.length(); j++) {
			vector<int> hashValue = getHashValue(s, i, j);
			mp[hashValue]++;
		}
	}

	int tot = 0;
	for (auto x : mp) {
		auto snd = x.second;
		tot += (snd) * (snd - 1) / 2;
	}

	return tot;
}


// least partitions required, similar to leetcode word break

int min_bars_helper(string s, vector<string> &words, int idx, unordered_set<string> &st) {
	if (idx == s.length()) {
		return 0;
	}

	int ans = INT_MAX;

	string current_string = "";

	for (int j = idx; j < s.length(); j++) {
		current_string += s[j];

		if (st.find(current_string) != st.end()) {
			int rem = min_bars_helper(s, words, j + 1, st);
			if (rem != -1) {
				ans = min(ans, 1 + rem);
			}
		}
	}

	if (ans == INT_MAX) {
		return -1;
	}

	return ans;
}

int min_bars(vector<string> &words, string s) {
	unordered_set<string> st;
	for (string word : words) {
		st.insert(word);
	}

	int output = min_bars_helper(s, words, 0, st);
	return output - 1;
}

///////////////////////////////////////////////////////////////////////////////

int main() {


	return 0;
}











