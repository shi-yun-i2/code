#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int max = 1;
        for (int i = 1; i < nums.size(); i++) {
            // 本位比前一位大的时候才更新数值
            if (nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + 1;
                // 顺便找最大值
                if (dp[i] > max) {
                    max = dp[i];
                }
            }
        }
        return max;
    }
};