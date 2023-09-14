#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    void bfs(vector<vector<char>>& g, int i, int j) {
        queue<pair<int, int>> q;
        g[i][j] = '0';
        q.push({i, j});
        while (!q.empty()) {
            pair<int, int> node = q.front();
            q.pop();
            int x = node.first;
            int y = node.second;
            for (int k = 0; k < 4; k++) {
                int xx = x + dx[k];
                int yy = y + dy[k];
                if (xx >= 0 && xx <= g.size() - 1 && yy >= 0 && yy <= g[0].size() - 1 && g[xx][yy] != '0') {
                    q.push({xx, yy});
                    g[xx][yy] = '0';
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
};

class Solution2 {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    void bfs(vector<vector<char>>& g, vector<vector<int>>& vis, int i, int j) {
        queue<pair<int, int>> q;
        int n = g.size();
        int m = g[0].size();
        q.push({i, j});
        vis[i][j] = 1;
        while (!q.empty()) {
            pair<int, int> node = q.front();
            q.pop();
            int x = node.first;
            int y = node.second;
            for (int k = 0; k < 4; k++) {
                int xx = x + dx[k];
                int yy = y + dy[k];
                if (xx >= 0 && xx <= n - 1 && yy >= 0 && yy <= m - 1 && !vis[xx][yy] && g[xx][yy] == '1') {
                    //加入队列 就代表走过，立刻标记
                    q.push({xx, yy});
                    vis[xx][yy] = 1;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    bfs(grid, vis, i, j);
                    res++;
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

    void dfs(vector<vector<char>>& g, vector<vector<bool>>& vis, int x, int y) {
        int n = g.size();
        int m = g[0].size();
        vis[x][y] = 1;
        for (int k = 0; k < 4; k++) {
            int xx = x + dx[k];
            int yy = y + dy[k];
            if (xx >= 0 && xx <= n - 1 && yy >= 0 && yy <= m - 1 && !vis[xx][yy] && g[xx][yy] == '1') {
                dfs(g, vis, xx, yy);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    dfs(grid, vis, i, j);
                    res++;
                }
            }
        }
        return res;
    }
};
