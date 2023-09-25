#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    int countSubstrings(string s) {
        int length = s.length();
        // dp[i][j]表示i,j是否是回文串
        // 开和字符串一样长的数组
        vector<vector<bool>> dp(length, vector<bool>(length, false));
        int result = 0;
        // 递推公式来自左下角,遍历从下向上,从左向右保证值已经被计算
        // i在左边,j在右边
        for (int i = length - 1; i >= 0; i--) {
            for (int j = i; j < length; j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 1 || dp[i + 1][j - 1]) {
                        result++;
                        dp[i][j] = true;
                    }
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            result += extend(s, i, i, s.size()); // 以i为中心
            result += extend(s, i, i + 1, s.size()); // 以i和i+1为中心
        }
        return result;
    }

    int extend(string& s, int i, int j, int n) {
        int res = 0;
        while (i >= 0 && j < n && s[i] == s[j]) {
            i--;
            j++;
            res++;
        }
        return res;
    }
};