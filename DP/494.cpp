#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        // 假设加法的总和为x，那么减法对应的总和就是sum - x。
        // 所以我们要求的是 x - (sum - x) = target
        // 即x = (target + sum) / 2
        // 就是求x为这个值时的方法总数
        // 如果sum + target为奇数,那么x < (target + sum) / 2
        // 也就是x - (sum - x) < target,不满足题意

        if ((sum + target) % 2 == 1) {
            return 0;
        }

        if (sum < abs(target)) {
            return 0;
        }

        int bagSize = (sum + target) / 2;

        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = bagSize; j >= nums[i]; j--) {
                // 当j < nums[i]的时候,要找到dp[j - nums[i]]的值
                // 但是要找凑成负数的情况即为0
                // 也就是说,如果使用nums[i],则无法找到与之对应的种类数满足可以凑成j,故此为终止循环条件
                // 相当于只要使用了nums[i]就已经超过了背包容量,所以结束

                // dp[j]是遍历到nums[i - 1]之前的数字可以组成j的总数
                // dp[j - nums[i]]是加入新的nums[i]后可以组成j的新方法数量
                // 两者相加即为遍历到nums[i]之前的数字可以组成j的总数

                // 为什么dp[j - nums[i]]是新的方法数量,因为它使用了nums[i],
                // 与之对应的dp[j - nums[i]]是没有使用nums[i]的方法总数 * 1(使用nums[i])
                // 两者结合则dp[j - nums[i]]是加入新的nums[i]后可以组成j的新方法数量

                dp[j] = dp[j] + dp[j - nums[i]];
            }
        }
        return dp[bagSize];
    }
};
