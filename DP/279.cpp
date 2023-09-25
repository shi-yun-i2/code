#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSquares(int bagSize) {
        int inf = 0x3f3f3f3f;
        // 要求最小值,初始化为最大值避免被覆盖
        // dp[j]:和为j的完全平方数的最少数量为dp[j]
        vector<int> dp(bagSize + 1, inf);
        // 不是累加的,初始化为0
        dp[0] = 0;

        // 循环变量i直接作为物品遍历,这个物品最多遍历到 i * i <= bagSize就够了
        // 如果i * i > bagSize,那么这个i没有被选择的必要,内层循环每一次都不会选择它
        for (int i = 1; i * i <= bagSize; i++) {
            for (int j = i * i; j <= bagSize; j++) {
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }
        return dp[bagSize];
    }
};

