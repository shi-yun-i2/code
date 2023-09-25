#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int length1 = text1.length();
        int length2 = text2.length();

        // dp[i][j]表示以i - 1和j - 1为结尾的两个字符串的最长公共子序列长度
        // 为了方便初始化,第一行和第一列相当于对空串求解,初始为0
        vector<vector<int>> dp(length1 + 1, vector<int>(length2 + 1, 0));

        // 因为i - 1和j - 1的特性,i和j需要遍历到字符串的末尾 + 1的位置,也就是字符串长度
        for (int i = 1; i <= length1; i++) {
            // 假设求x和y的公共子序列,当他们两个的最后一个数相等,
            // 那么最后一个数一定在最大公共子序列中,就等于x和y都减去最后一个数的公共子序列 + 1

            // 但如果x和y最后一个数不相同,那么如果要求最大公共子序列,
            // 最大公共子序列最多只能满足他们俩当中的一个,
            // 也就是只会在dp[i - 1][j]和dp[i][j - 1]出现
            for (int j = 1; j <= length2; j++) {
                // 如果两个字符串末尾字符相同,则相当于两个字符串同时后退一位再加这个字符的1
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    // 相对于左上角i-1,j-1,由于两个方向各引入了一个新的字符,它的左侧和上侧可能匹配到了对应的字符,这时即使两个末尾不相同也可以更新
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        // 根据dp数组含义这个就是要求的值
        return dp[length1][length2];
    }
};