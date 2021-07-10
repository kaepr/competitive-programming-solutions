#include <bits/stdc++.h>
using namespace std;
 
double euclidian(pair<int,int> p1, pair<int,int> p2) {
	return sqrt(pow(p2.first-p1.first, 2) + pow(p2.second-p1.second, 2));
}
 
int main() {
	int n, m, x;
	cin >> n; cin >> m; cin >> x;
 
 
	// n -> rows of keys
	// m -> number of keys / row
	// x -> ubound of size
 
	vector<vector<char>> keyboard(n, vector<char>(m));
	vector<pair<int,int>> s_keys;
 
	for (int i = 0; i < keyboard.size(); i++) {
		for (int j = 0; j < keyboard[i].size(); j++) {
			char key; cin >> key;
			keyboard[i][j] = key;
			if (key == 'S') s_keys.push_back({i, j});
		}
	}
 
	int throwaway; cin >> throwaway;
 
	string s;
	cin >> s;
	unordered_map<char, double> seen;
 
	for (int i = 0; i < keyboard.size(); i++) {
		for (int j = 0 ; j < keyboard[i].size(); j++){
			if (keyboard[i][j] == 'S') continue;
			if (seen.find(keyboard[i][j]) == seen.end())
				seen[keyboard[i][j]] = DBL_MAX;
 
			for (auto shift : s_keys)
				seen[keyboard[i][j]] = std::min(seen[keyboard[i][j]], euclidian({i,j}, shift));
		}
	}
 
	int cnt = 0;
	for (auto byte : s) {
		if (seen.find(byte) == seen.end() && seen.find(tolower(byte)) == seen.end()) {
			cout << -1 << endl;
			return 0;
		} else {
			if (seen.find(byte) == seen.end()) {
				if (seen[tolower(byte)] == DBL_MAX) {
					cout << -1 << endl;
					return 0;
				}
				if (seen[tolower(byte)] > x)
					cnt++;
			}
		}
	}
 
	cout << cnt << endl;
	return 0;
}