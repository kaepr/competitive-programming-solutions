#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll MOD = 1e9 + 7;

int N = 8;
vector<vector<char>> board;

bool is_safe(int row, int col) {
  if (board[row][col] != '.') {
    return false;
  }

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j] == 'Q') {
        // check for same column
        if (j == col) {
          return false;
        }

        // check for same diagonal
        if (abs(i - row) == abs(j - col)) {
          return false;
        }
      }
    }
  }

  return true;
}

int calc(int row) { // defines level
  if (row == N) {
    return 1;
  }

  int ways = 0;
  // choosing which column
  for (int col = 0; col < N; col++) {
    if (is_safe(row, col)) { // checking if its safe or not
      board[row][col] = 'Q';
      ways += calc(row + 1);
      board[row][col] = '.'; //  revert choice
    }
  }

  return ways;
}

void solve() {
  board = vector<vector<char>>(N, vector<char>(N, '.'));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }

  // for (auto x : board) {
  //   for (auto y : x) {
  //     cout << y << " ";
  //   }
  //   cout << "\n";
  // }

  int ans = calc(0);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}
