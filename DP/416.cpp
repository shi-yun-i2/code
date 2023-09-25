#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // int sum = accumulate(nums.begin(), nums.end(), 0);
        // 求和库函数适用于支持 operator+ 的数据类型
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        if (sum % 2 != 0) {
            return false;
        }
        int bagSize = sum / 2;

        // 如果题目给的价值有负数，那么非0下标就要初始化为负无穷
        vector<int> dp(bagSize + 1, 0);

        // 先遍历物品后容量,遍历物品数组
        for (int i = 0; i < nums.size(); i++) {
            // j < nums[i]的情况没有更新dp数组,相当于直接取的上一次状态,即dp[i - 1][j]
            // 注意:j--
            for (int j = bagSize; j >= nums[i]; j--) {
                // 第一行的初始化以 全为0的上一行 为前一个状态
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        // 是否可以装满
        return dp[bagSize] == bagSize;
    }
};
