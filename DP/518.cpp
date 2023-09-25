#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int change(int bagSize, vector<int>& coins) {
        // dp[j]:凑成总金额j的货币组合数为dp[j]
        vector<int> dp(bagSize + 1, 0);
        // 初始化:求方法数第一个数初始化为1
        dp[0] = 1;

        // 先物品后背包求组合数
        for (int i = 0; i < coins.size(); i++) {
            // 正向遍历求完全背包,j初始化为coins[i]
            for (int j = coins[i]; j <= bagSize; j++) {
                // 每次更新一行背包容量
                // 假设：coins[0] = 1，coins[1] = 5。
                // 那么就是先把1加入计算，然后再把5加入计算，得到的方法数量只有{1, 5}这种情况。而不会出现{5, 1}的情况。
                dp[j] = dp[j] + dp[j - coins[i]];
            }
        }
        return dp[bagSize];
    }
};

