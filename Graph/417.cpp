#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& vis, int x, int y) {
        int n = heights.size();
        int m = heights[0].size();
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 0 && xx <= n - 1 && yy >= 0 && yy <= m - 1 && !vis[xx][yy] && heights[xx][yy] >= heights[x][y]) {
                dfs(heights, vis, xx, yy);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> pacific(n, vector<bool>(m, 0));
        vector<vector<bool>> atlantic(n, vector<bool>(m, 0));

        for (int i = 0; i < n; i++) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, m - 1);
        }

        for (int i = 0; i < m; i++) {
            dfs(heights, pacific, 0, i);
            dfs(heights, atlantic, n - 1, i);
        }

        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};

