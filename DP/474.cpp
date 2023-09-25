#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // m和n相当于两个维度的背包容量
        // 两个维度的零一背包,weight为消耗值,value为增加值
        // 最多有i个0和j个1的strs的最大子集的大小为dp[i][j]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // 相当于二维的weight[i],使用该元素需要付出的代价
        vector<int> zero(strs.size(), 0);
        vector<int> one(strs.size(), 0);

        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            for (int j = 0; j < str.length(); j++) {
                if (str[j] == '0') {
                    zero[i]++;
                }
                if (str[j] == '1') {
                    one[i]++;
                }
            }
        }

        // 滚动数组
        for (int i = 0; i < strs.size(); i++) {
            for (int j = m; j >= zero[i]; j--) {
                for (int k = n; k >= one[i]; k--) {
                    // "1"是使用该元素获得的价值
                    // 可以选择不要这个元素,也可以选择以前面一种状态要这个元素
                    dp[j][k] = max(dp[j][k], dp[j - zero[i]][k - one[i]] + 1);
                }
            }
        }

        return dp[m][n];
    }
};

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // 数组可变大小的对象无法初始化，也就是在声明可变大小的对象时，不能同时进行初始化。
        // 这里n是可变大小的，在较新的编译器中用变量(如n)定义数组是被允许的，
        // 但是不能同时进行初始化，如有需要可在后续的步骤中进行初始化。
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));

        // 嵌套的for循环只有三层
        // 对每个字符串操作,不用储存下来
        for (string str : strs) {
            int zero = 0;
            int one = 0;
            for (int i = 0; i < str.length(); i++) {
                if (str[i] == '0') {
                    zero++;
                }
                if (str[i] == '1') {
                    one++;
                }
            }

            for (int i = m; i >= zero; i--) {
                for (int j = n; j >= one; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zero][j - one] + 1);
                }
            }
        }
        return dp[m][n];
    }
};