#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];

        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        for (int i = 0; i < n; i++) {
            dp[0][i] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // 左边和上边都已经有值,从这两个状态转换
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[n];
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
        }
        // 进行m次行更新
        for (int j = 1; j < m; j++) {
            // 对列中的每个元素更新
            for (int i = 1; i < n; i++) {
                // 第0个元素是1,dp[i]表示从上方过来的方法种数
                // dp[i-1]由于已经更新过,表示本行从左侧过来的方法种数
                dp[i] += dp[i - 1];
            }
        }
        return dp[n - 1];
    }
};