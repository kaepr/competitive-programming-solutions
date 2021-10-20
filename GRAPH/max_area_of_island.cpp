#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/max-area-of-island/

class Solution {
public:

    int dfs(
        vector<vector<int>> &grid,
        vector<vector<bool>> &vis,
        int i,
        int j,
        int m,
        int n
    ) {
        vis[i][j] = true;
        int cs = 1;


        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        for (int k = 0; k < 4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if (nx >= 0 and nx<m and ny >= 0 and ny < n and grid[nx][ny] and !vis[nx][ny]) {
                cs += dfs(grid, vis, nx, ny, m, n);
            }
        }

        return cs;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] and grid[i][j]) {
                    int sz = dfs(grid, vis, i, j, m, n);
                    ans = max(sz, ans);
                }
            }
        }

        return ans;
    }
};