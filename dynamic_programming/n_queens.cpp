#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll MOD = 1e9 + 7;

// Size of the chessboard
int N = 4;

// Can be changed to vector<int> which stores only which column
// queen is placed at
vector<vector<int>> board;
vector<pair<int, int>> dirs = {{-1, -1}, {1, -1}, {1, 1}, {-1, 1}};

bool is_safe_optimized(int row, int col) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j]) {
        // checks for same column
        // And for same diagonal using the second condition
        // Cells belong to the same diagonal if there
        // abs(row) and abs(col) are the same

        if (j == col || abs(i - row) == abs(j - col)) {
          return false;
        }

        // below gives wrong output
        // return !(j == col || abs(i - row) == abs(j - col));
      }
    }
  }

  return true;
}

bool is_safe(int row, int col) {
  if (board[row][col]) {
    return false;
  }

  // row empty
  for (int i = 0; i < N; i++) {
    if (board[row][i]) {
      return false;
    }
  }

  // column empty
  for (int i = 0; i < N; i++) {
    if (board[i][col]) {
      return false;
    }
  }

  // diagonals
  for (auto dir : dirs) {
    int nr = row, nc = col;

    auto in_bounds = [&](int x, int y) {
      return x >= 0 and x < N and y >= 0 and y < N;
    };

    while (in_bounds(nr, nc)) {
      if (board[nr][nc]) {
        return false;
      }

      nr += dir.first;
      nc += dir.second;
    }
  }

  return true;
}

int rec(int row) {
  if (row == N) {
    // done placing all the queens
    // print board configuration if required
    return 1;
  }

  int ans = 0;

  // choosing which column to place at
  for (int col = 0; col < N; col++) {
    if (is_safe(row, col)) {
      // potentially valid position

      board[row][col] = 1;
      ans += rec(row + 1);
      // backtrack at position
      // try out other columns for this row
      board[row][col] = 0;
    }
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  board = vector<vector<int>>(N, vector<int>(N, 0));
  int ans = rec(0);

  cout << "#ways = " << ans << "\n";

  return 0;
}
