#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        // dp[i]表示n个节点形成的树的种类个数
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        // i是全部节点个数
        for (int i = 1; i <= n; i++) {
            // 变量j是左子树节点个数
            for (int j = 0; j <= i - 1; j++) {
                // i - j - 1是右子树节点个数
                // 方案数都是累加(左子树*右子树)
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }

        return dp[n];
    }
};
