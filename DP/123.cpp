#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0) {
            return 0;
        }
        // 1表示第一次持有股票
        // 2表示第一次不持有股票
        // 3表示第二次持有股票
        // 4表示第二次不持有股票
        vector<vector<int>> dp(len, vector<int>(5, 0));
        // 类比第一天的操作
        dp[0][1] = -prices[0];
        dp[0][2] = 0;
        // 第一天买入,卖出,再买入
        dp[0][3] = -prices[0];
        dp[0][4] = 0;
        for (int i = 1; i < len; i++) {
            dp[i][1] = max(dp[i - 1][1], 0 - prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            // 注意状态的转移条件,第二吃持有股票,从第一次把股票卖出,即第一次不持有股票转化而来
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }
        // dp[i][j]中 i表示第i天,j为[1 - 4]四个状态,dp[i][j]表示第i天状态j所剩最大现金,
        // 第二次不持有肯定最大,如果第二次交易无法获利,会延续第一次的现金
        // 如果第一次卖出已经是最大值了，那么我们可以在当天立刻买入再立刻卖出。
        //  所以dp[4][4]已经包含了dp[4][2]的情况。也就是说第二次卖出手里所剩的钱一定是最多的。
        return dp[len - 1][4];
    }
};