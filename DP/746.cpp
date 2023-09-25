#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[cost.size() + 1];
        // 站在前两个台阶上没有消耗
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= cost.size(); i++) {
            // 选择前两层和前一层到本层花费中的较小值
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        // 跳到最后一格的上面,离开数组才表示爬完楼梯
        return dp[cost.size()];
    }
};