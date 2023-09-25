#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // dp[i][j]表示以i - 1和j - 1为 结尾 的两个数组的最长重复子数组长度
        // 由于子数组要求连续,所以包含了一个新元素后的最长重复子数组长度可能会清零
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int max = 0;

        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                // 必须要求前一个元素相同才能进行状态转换
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    if (dp[i][j] > max) {
                        max = dp[i][j];
                    }
                }
            }
        }
        return max;
    }
};