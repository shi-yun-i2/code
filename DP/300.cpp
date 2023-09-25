#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        // 每个元素默认最长递增子序列为"1"
        // 初始化为1避免全部元素相同的情况
        int maxx = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                // 严格递增
                if (nums[i] > nums[j]) {
                    // 取目前和选取前面元素的最大值
                    dp[i] = max(dp[i], dp[j] + 1);
                    if (dp[i] > maxx) {
                        maxx = dp[i];
                    }
                }
            }
        }
        return maxx;
    }
};