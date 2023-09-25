#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // 奇数情况是持有,偶数情况是不持有,增加0状态方便dp[1]的赋值
        // 第i天的状态为j，所剩下的最大现金是dp[i][j]
        vector<vector<int>> dp(n, vector<int>(2 * k + 1, 0));
        // 对于第一天来说,所有买入情况的现金都是-prices[0]
        for (int i = 1; i < 2 * k + 1; i += 2) {
            dp[0][i] = -prices[0];
        }
        for (int i = 1; i < n; i++) {
            // j枚举持有,j+1枚举不持有
            for (int j = 1; j < 2 * k + 1; j += 2) {
                // 上一天不持有买入为减
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
                // 上一天持有卖出为加
                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] + prices[i]);
            }
        }
        return dp[n - 1][2 * k];
    }
};

