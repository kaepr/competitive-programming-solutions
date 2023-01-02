// https://www.learning.algozenith.com/problems/N-Queens-Revisited-137

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll MOD = 1e9 + 7;
int n;

vector<pair<int, int>> knight_moves = {{-1, 2},  {1, 2},  {-2, 1},  {2, 1},
                                       {-2, -1}, {2, -1}, {-1, -2}, {1, -2}};    

bool is_safe(int row, int col, vector<vector<int>> &board) {
  if (board[row][col] == 1) {
    return false;
  }

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == 1) {
        // check for same column
        if (j == col) {
          return false;
        }

        // check for same diagonal
        if (abs(i - row) == abs(j - col)) {
          return false;
        }

        // check knight move
        auto in_bounds = [&](int x, int y) {
          return x >= 0 and x < n and y >= 0 and y < n;
        };

        for (auto move : knight_moves) {
          int nr = i + move.first;
          int nc = j + move.second;

          if (in_bounds(nr, nc)) {
            if (nr == row and nc == col) {
              return false;
            }
          }
        }
      }
    }
  }

  return true;
}

int calc(int row, vector<vector<int>> &board) {
  if (row == n) {
    return 1;
  }

  int ways = 0;
  // choosing which column
  for (int col = 0; col < n; col++) {
    if (is_safe(row, col, board)) { // checking if its safe or not
      board[row][col] = 1;
      ways += calc(row + 1, board);
      board[row][col] = 0; //  revert choice
    }
  }

  return ways;
}

void solve() {
  cin >> n;

  vector<vector<int>> board(n, vector<int>(n, 0));

  int ans = calc(0, board);

  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}
