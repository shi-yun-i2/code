#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    int integerBreak(int n) {
        // dp[i] 表示将正整数 i 拆分成至少两个正整数的和之后，这些正整数的最大乘积
        vector<int> dp(n + 1, 0);
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            // j用于枚举将数 n 拆分成若干个正整数之和时最小的加数
            // 拆分一个数n使之乘积最大，那么一定是拆分成m个近似相同的子数相乘才是最大的
            // 可以明确的是m一定大于等于2，既然m大于等于2，也就是 最差也应该是拆成两个相同的 可能是最大值
            for (int j = 1; j <= i / 2; j++) {
                dp[i] = max(dp[i], max((i - j) * j, j * dp[i - j]));
            }
        }
        return dp[n];
    }
};

class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        if (n == 4) return 4;
        int result = 1;
        // 每次拆成n个3，如果剩下是4，则保留4，然后相乘
        while (n > 4) {
            result *= 3;
            n -= 3;
        }
        result *= n;
        return result;
    }
};