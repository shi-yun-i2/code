#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    void dfs(vector<vector<char>>& g, vector<vector<bool>>& vis, int x, int y) {
        int n = g.size();
        int m = g[0].size();
        vis[x][y] = 1;
        g[x][y] = 'A';
        for (int k = 0; k < 4; k++) {
            int xx = x + dx[k];
            int yy = y + dy[k];
            if (xx >= 0 && xx <= n - 1 && yy >= 0 && yy <= m - 1 && !vis[xx][yy] && g[xx][yy] == 'O') {
                dfs(g, vis, xx, yy);
                g[xx][yy] = 'A';
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && !vis[i][0]) {
                dfs(board, vis, i, 0);
            }
            if (board[i][m - 1] == 'O' && !vis[i][m - 1]) {
                dfs(board, vis, i, m - 1);
            }
        }
        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O' && !vis[0][i]) {
                dfs(board, vis, 0, i);
            }
            if (board[n - 1][i] == 'O' && !vis[n - 1][i]) {
                dfs(board, vis, n - 1, i);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    void dfs(vector<vector<char>>& g, int x, int y) {
        int n = g.size();
        int m = g[0].size();
        g[x][y] = 'A';
        for (int k = 0; k < 4; k++) {
            int xx = x + dx[k];
            int yy = y + dy[k];
            if (xx >= 0 && xx <= n - 1 && yy >= 0 && yy <= m - 1 && g[xx][yy] == 'O') {
                dfs(g, xx, yy);
                g[xx][yy] = 'A';
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0);
            }
            if (board[i][m - 1] == 'O') {
                dfs(board, i, m - 1);
            }
        }
        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O') {
                dfs(board, 0, i);
            }
            if (board[n - 1][i] == 'O') {
                dfs(board, n - 1, i);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
