#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        // dp[i][j]:要使word1的前i个字符和word2的前j个字符相同所需要删除元素的最少次数
        int dp[len1 + 1][len2 + 1];
        for (int i = 0; i <= len1; i++) {
            dp[i][0] = i;
        }
        for (int i = 0; i <= len2; i++) {
            dp[0][i] = i;
        }
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // 删除j - 1,删除i - 1,两个都删除
                    dp[i][j] = min(min(dp[i][j - 1] + 1, dp[i - 1][j] + 1), dp[i - 1][j - 1] + 2);
                }
            }
        }
        return dp[len1][len2];
    }
};

class Solution2 {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return word1.size() + word2.size() - dp[word1.size()][word2.size()] * 2;
    }
};

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int dp[n + 1][m + 1];
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }
        for (int i = 0; i <= m; i++) {
            dp[0][i] = i;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // word1的前i个字符已经和word2的前j-1个字符相同,要使word1的前i个字符和word2的前j个字符相同
                    // 需要将word2的第j-1个字符删除

                    // word1的前i-1个字符已经和word2的前j个字符相同,要使word1的前i个字符和word2的前j个字符相同
                    // 需要将word1的第i-1个字符删除
                    dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + 1;
                }
            }
        }
    }
};