#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 等于斐波那契数列
    int climbStairs(int n) {
        // 每一层楼可以由前两层楼跨两层得到,也可以由前一层跨一层得到
        if (n <= 1) {
            return n;
        }
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        // 可以不初始化dp[0],实际上dp[1]是斐波那契数列的第二项
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};