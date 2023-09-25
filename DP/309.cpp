#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // 1表示持有股票状态（今天买入股票，或者是之前就买入了股票然后没有操作，一直持有）
        // 不持有股票状态，这里就有两种卖出股票状态
        // 2表示保持卖出股票的状态（两天前就卖出了股票，度过一天冷冻期。或者是前一天就是卖出股票状态，一直没操作）
        // 3表示今天卖出股票
        // 4表示今天是冷冻期(不持有股票)
        vector<vector<int>> dp(n, vector<int>(5, 0));
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            dp[i][1] = max(max(dp[i - 1][1], dp[i - 1][2] - prices[i]), dp[i - 1][4] - prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][3]);
            dp[i][3] = dp[i - 1][1] + prices[i];
            dp[i][4] = dp[i - 1][3];
        }
        // 只要不持有股票都有可能是最大值
        return max(max(dp[n - 1][2], dp[n - 1][3]), dp[n - 1][4]);
    }
};
