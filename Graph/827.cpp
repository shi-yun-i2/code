#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    map<int, int> mapp;

    void dfs(vector<vector<int>>& g, vector<vector<bool>>& vis, vector<vector<int>>& number, int x, int y, int sign) {
        int n = g.size();
        int m = g[0].size();
        vis[x][y] = true;
        mapp[sign]++;
        number[x][y] = sign;
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && !vis[xx][yy] && g[xx][yy] == 1) {
                dfs(g, vis, number, xx, yy, sign);
            }
        }
    }

    int largestIsland(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        int sign = 0;
        int flag = true;
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        vector<vector<int>> number(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 0) {
                    flag = false;
                }
                if (!vis[i][j] && g[i][j] == 1) {
                    sign++;
                    dfs(g, vis, number, i, j, sign);
                }
            }
        }

        if (flag) {
            return n * m;
        }

        set<int> sett;
        int count = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                count = 0;
                sett.clear();
                if (g[i][j] == 0) {
                    for (int k = 0; k < 4; k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (x < 0 || x >= n || y < 0 || y >= m) {
                            continue;
                        }
                        int mark = number[x][y];
                        if (mark != 0 && sett.count(mark) == 0) {
                            count += mapp[mark];
                            sett.insert(mark);
                        }
                    }
                }
                res = max(res, count);
            }
        }
        return res + 1;
    }
};


class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    map<int, int> mapp;

    void dfs(vector<vector<int>>& g, vector<vector<int>>& number, int x, int y, int sign) {
        int n = g.size();
        int m = g[0].size();
        mapp[sign]++;
        number[x][y] = sign;
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && number[xx][yy] == 0 && g[xx][yy] == 1) {
                dfs(g, number, xx, yy, sign);
            }
        }
    }

    int largestIsland(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        int sign = 0;
        int flag = true;
        vector<vector<int>> number(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 0) {
                    flag = false;
                }
                if (number[i][j] == 0 && g[i][j] == 1) {
                    sign++;
                    dfs(g, number, i, j, sign);
                }
            }
        }

        if (flag) {
            return n * m;
        }

        set<int> sett;
        int count = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                count = 0;
                sett.clear();
                if (g[i][j] == 0) {
                    for (int k = 0; k < 4; k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (x < 0 || x >= n || y < 0 || y >= m) {
                            continue;
                        }
                        int mark = number[x][y];
                        if (mark != 0 && sett.count(mark) == 0) {
                            count += mapp[mark];
                            sett.insert(mark);
                        }
                    }
                }
                res = max(res, count);
            }
        }
        return res + 1;
    }
};