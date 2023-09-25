#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int row = g.size();
        int col = g[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));

        // 初始化为0，不用再找障碍和初始化第一行列障碍物后的数值
        for (vector<int>& arr : dp) {
            fill(arr.begin(), arr.end(), 0);
        }

        // for结束条件
        for (int i = 0; i < col && g[0][i] == 0; i++) {
            dp[0][i] = 1;
        }
        for (int i = 0; i < row && g[i][0] == 0; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                // (i, j)如果就是障碍的话应该就保持初始状态0
                if (g[i][j] != 1) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[row - 1][col - 1];
    }
};
