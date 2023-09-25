#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int len1 = s.size();
        int len2 = t.size();
        // 第一种处理方式
        uint64_t dp[len1 + 1][len2 + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= len1; i++) {
            dp[i][0] = 1;
        }
        for (int i = 0; i <= len2; i++) {
            dp[0][i] = 0;
        }
        dp[0][0] = 1;
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                // 第二种处理方式
                // dp[i-1][j]可以看成在s[0:i-2]子序列中找t[0:j-1]中总共出现多少次，
                // 这一项其实不用管s[i-1]和t[j-1]到底相不相等，就是一个base；
                // 然后在这个base基础上又多出来一些情况，也就是s[i-1]和t[j-1]相等时dp[i-1][j-1]。
                // 因此dp[i-1][j]可以看成base，dp[i-1][j-1]可以看成增量，二者相加就是dp[i][j]考虑的所有情况
                // s[i-1]与t[j-1]不相等时，dp[i-1][j]也可以看成base，只是这时候没有多余的情况，即增量为0
                if (s[i - 1] == t[j - 1] && dp[i - 1][j - 1] < INT_MAX - dp[i - 1][j]) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[len1][len2];
    }
};