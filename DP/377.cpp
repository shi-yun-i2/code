#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int bagSize) {
        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1;

        // 先遍历背包后物品求排列,i和j都初始化为0
        for (int i = 0; i <= bagSize; i++) {
            for (int j = 0; j < nums.size(); j++) {
                // 增加判断条件防止数组越界,防止爆int
                // 答案保证最终答案的组合数在32位范围内，
                // 但是如果在target之前的数字组合数是可能超过INT_MAX的，
                // 但因为最终答案不会超过，所以target肯定不会利用到这些超过INT_MAX的数据的，
                // 所以忽略掉那些会超过INT_MAX的就可以
                if (i >= nums[j] && dp[i] < INT_MAX - dp[i - nums[j]]) {
                    // 求方法总数的递推公式
                    // 每次遍历物品时把该物品放在第一个 <----------------------------------
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[bagSize];
    }
};
