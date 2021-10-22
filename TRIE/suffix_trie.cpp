#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Node {
public:
	char data;
	unordered_map<char, Node*> m;
	bool isTerminal;

	Node(char d) {
		data = d;
		isTerminal = false;
	}
};

class SuffixTrie {
public:
	Node* root;
	SuffixTrie() {
		root = new Node('\0');
	}

	void insert_helper(string word) {
		Node* tmp = root;

		for (char ch : word) {
			if (tmp->m.count(ch) == 0) {
				Node* n = new Node(ch);
				tmp->m[ch] = n;
			}
			tmp = tmp->m[ch];
		}

		tmp->isTerminal = true;
	}

	bool search(string word) {
		Node* tmp = root;

		for (char ch : word) {
			if (tmp->m.count(ch) == 0) {
				return false;
			}
			tmp = tmp->m[ch];
		}

		return tmp->isTerminal;
	}

	void insert(string word) {
		for (int i = 0; i < word[i] != '\0'; i++) {
			insert_helper(word.substr(i));
		}
	}
};



void solve() {
	string words[] = {
		"apple",
		"ape",
		"no",
		"news",
		"not",
		"never"
	};

	SuffixTrie t;
	for (auto word : words) {
		t.insert(word);
	}

	int q;
	cin >> q;
	cout << q << "\n";
	string search_words;
	while (q) {
		cin >> search_words;
		if (t.search(search_words)) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
		q--;
		// break;
	}
}

int main() {

	int t = 1;
	// cin >> t;
	while (t > 0) {
		solve();
		t--;
	}

	return 0;
}