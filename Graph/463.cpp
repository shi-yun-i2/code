#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    for (int k = 0; k < 4; k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (x < 0 || x >= n || y < 0 || y >= m) {
                            res++;
                            continue;
                        }
                        if (grid[x][y] == 0) {
                            res++;
                        }
                    }
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int land = 0;
        int adjoin = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    land++;
                    int x1 = i - 1;
                    int y1 = j;
                    if (!(x1 < 0 || x1 >= n || y1 < 0 || y1 >= m)) {
                        if (grid[x1][y1] == 1) {
                            adjoin++;
                        }
                    }

                    int x2 = i;
                    int y2 = j - 1;
                    if (!(x2 < 0 || x2 >= n || y2 < 0 || y2 >= m)) {
                        if (grid[x2][y2] == 1) {
                            adjoin++;
                        }
                    }
                }
            }

        }
        return land * 4 - adjoin * 2;
    }
};
