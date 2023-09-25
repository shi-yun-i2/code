#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int length = s.length();
        vector<bool> dp(length + 1, false);
        dp[0] = true;

        // 双指针扫描,j在前面,i在后面
        for (int i = 1; i <= length; i++) {
            // 背包问题的变种,j通过在wordDict查找有无子串来遍历物品
            // j枚举0-i的全部起始位置
            // dp[i]如果是true,不用进行循环
            // 内层循环的最终目的就是判断dp[i]是否为真
            for (int j = 0; j < i && !dp[i]; j++) {
                // j可以凑成且字典中存在j到i的子串
                if (dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()) {
                    dp[i] = true;
                    // 找到之后可以直接结束本轮循环,因为已经设置为true了
                    break;
                }
            }
        }
        return dp[length];
    }
};