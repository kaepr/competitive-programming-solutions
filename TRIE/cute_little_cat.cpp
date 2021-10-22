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

class Trie {
public:
	Node* root;
	Trie() {
		root = new Node('\0');
	}

	void insert(string word) {
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
};

void searchHelper(Trie t, string document, int i, unordered_map<string, bool> &m) {
	Node* tmp = t.root;
	for (int j = i; j < document.length(); j++) {
		if (tmp->children.count(ch) == 0) {
			return;
		}
		tmp = tmp->children[ch];
		if (tmp->isTerminal) {
			string out = document.substr(i, j - i + 1);
			m[out] = true;
		}
	}
}

void documentSearch(string document, vector<string> words) {
	Trie t;
	for (auto w : words) {
		t.insert(w);
	}

	unordered_map<string, bool> m;
	for (int i = 0; i < document.length(); i++) {
		searchHelper(t, document, i, m);
	}

	for (auto w : words) {
		if (m[w]) {
			cout << w << " ";
		}
	}



}

void solve() {
	string document = "a b c d";
	vector<string> words = {"a", "b", "asd"};
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