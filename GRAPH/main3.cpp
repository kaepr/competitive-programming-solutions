#include <bits/stdc++.h>
using namespace std;


// ===== Custom Node Class, if required
class Node {
public:
	string name;
	list<string> nbrs;

	Node(string name) {
		this->name = name;
	}
};

class GraphWithNode {
	unordered_map<string, Node*> m;
public:
	Graph(vector<string> cities) {
		for (auto city : cities) {
			m[city] = new Node(city);
		}
	}

	void addEdge(string x, string y, bool undir = false) {
		m[x]->nbrs.push_back(y);
		if (undir) {
			m[y]->nbrs.push_back(x);
		}
	}
};
