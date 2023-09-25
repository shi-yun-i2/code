#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int robbery(vector<int>& nums, int start, int end) {
        if (start == end) {
            return nums[start];
        }
        vector<int> dp(nums.size(), 0);
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[end];
    }

    int rob(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums[0];
        }
        // 首尾都不偷的情况已经被包含
        int res1 = robbery(nums, 0, nums.size() - 2);
        int res2 = robbery(nums, 1, nums.size() - 1);
        return max(res1, res2);
    }
};