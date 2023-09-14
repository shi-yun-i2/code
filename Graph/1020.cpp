#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int count;

    void dfs(vector<vector<int>>& g, vector<vector<bool>>& vis, int x, int y) {
        int n = g.size();
        int m = g[0].size();
        vis[x][y] = 1;
        g[x][y] = 0;
        count++;
        for (int k = 0; k < 4; k++) {
            int xx = x + dx[k];
            int yy = y + dy[k];
            if (xx >= 0 && xx <= n - 1 && yy >= 0 && yy <= m - 1 && !vis[xx][yy] && g[xx][yy] == 1) {
                dfs(g, vis, xx, yy);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1 && !vis[i][0]) {
                dfs(grid, vis, i, 0);
            }
            if (grid[i][m - 1] == 1 && !vis[i][m - 1]) {
                dfs(grid, vis, i, m - 1);
            }
        }
        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 1 && !vis[0][i]) {
                dfs(grid, vis, 0, i);
            }
            if (grid[n - 1][i] == 1 && !vis[n - 1][i]) {
                dfs(grid, vis, n - 1, i);
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    count = 0;
                    dfs(grid, vis, i, j);
                    res += count;
                }
            }
        }
        return res;
    }
};


class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int count;

    void bfs(vector<vector<int>>& g, vector<vector<bool>>& vis, int i, int j) {
        int n = g.size();
        int m = g[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = true;
        g[i][j] = 0;
        count++;
        while (!q.empty()) {
            pair<int, int> node = q.front();
            q.pop();
            int x = node.first;
            int y = node.second;
            for (int k = 0; k < 4; k++) {
                int xx = x + dx[k];
                int yy = y + dy[k];
                if (xx >= 0 && xx <= n - 1 && yy >= 0 && yy <= m - 1 && !vis[xx][yy] && g[xx][yy] == 1) {
                    q.push({xx, yy});
                    vis[xx][yy] = true;
                    g[xx][yy] = 0;
                    count++;
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1 && !vis[i][0]) {
                bfs(grid, vis, i, 0);
            }
            if (grid[i][m - 1] == 1 && !vis[i][m - 1]) {
                bfs(grid, vis, i, m - 1);
            }
        }
        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 1 && !vis[0][i]) {
                bfs(grid, vis, 0, i);
            }
            if (grid[n - 1][i] == 1 && !vis[n - 1][i]) {
                bfs(grid, vis, n - 1, i);
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    count = 0;
                    bfs(grid, vis, i, j);
                    res += count;
                }
            }
        }
        return res;
    }
};