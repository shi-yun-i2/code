#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0) {
            return 0;
        }
        vector<vector<int>> dp(len, vector<int>(2, 0));
        // 0表示不持有股票,1表示持有股票
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < len; i++) {
            // 前一天不持有股票,前一天持有股票当天卖出
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            // 前一天持有股票,前一天不持有股票当天买进
            // 由于只能买一次,所以当天买进的现金必须是-price[i]
            dp[i][1] = max(dp[i - 1][1], -prices[i]);
        }
        // 没有股票时手中现金更多
        return dp[len - 1][0];
    }
};