#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    // 只用到两个值,可以循环利用
    int fib(int n) {
        if (n <= 1) {
            return n;
        }
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};


class Solution {
public:
    // 递归
    int fib(int n) {
        if (n <= 1) {
            return n;
        }
        return fib(n - 1) + fib(n - 2);
    }
};

