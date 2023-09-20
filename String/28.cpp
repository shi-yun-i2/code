#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    int strStr(string s, string p) {
        int n = s.size();
        int m = p.size();
        // 记录每一个位置的最长公共前后缀的位置(用下标表示)
        int next[m];
        // 初始化next[0],注意:初始化为j的初始位置
        next[0] = -1;
        // 从模式串的第二个字符开始扫描,j永远初始化为第一个字符之前的值(扫描模式串)
        for (int i = 1, j = -1; i < m; i++) {
            // j > -1表示j不为初始值时进行循环
            // i指针在前,比较j的后一个字符,对j做出预判
            while (j > -1 && p[i] != p[j + 1]) {
                // j指针移动到前面,既然此处无法匹配,我们找到要求更低,即公共前后缀更短的位置重新尝试
                j = next[j];
            }
            // 如果预判成功,给j指针++
            if (p[i] == p[j + 1]) {
                j++;
            }
            // 确定好了j的位置,将其赋值给next[i]
            next[i] = j;
        }

        // 从文本串的第一个字符开始扫描
        for (int i = 0, j = -1; i < n; i++) {
            // i指针扫描文本串,j指针扫描模式串
            while (j > -1 && s[i] != p[j + 1]) {
                j = next[j];
            }
            if (s[i] == p[j + 1]) {
                j++;
            }
            // 从0开始j表示下标,从1开始表示第j个
            if (j == m - 1) {
                // 求下标返回i - j,求第几个返回i - j + 1
                return i - j;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int strStr(string ss, string pp) {
        int n = ss.size();
        int m = pp.size();
        char s[n + 1];
        char p[m + 1];
        for (int i = 0; i < n; i++) {
            s[i + 1] = ss[i];
        }
        for (int i = 0; i < m; i++) {
            p[i + 1] = pp[i];
        }

        // 记录每一个位置的最长公共前后缀的位置(用第几个表示) -->最长公共前后缀长度
        int next[m + 1];
        next[1] = 0;
        for (int i = 2, j = 0; i <= m; i++) {
            while (j && p[i] != p[j + 1]) {
                j = next[j];
            }
            if (p[i] == p[j + 1]) {
                j++;
            }
            next[i] = j;
        }

        for (int i = 1, j = 0; i <= n; i++) {
            while (j && s[i] != p[j + 1]) {
                j = next[j];
            }
            if (s[i] == p[j + 1]) {
                j++;
            }
            if (j == m) {
                return i - j;
            }
        }
        return -1;
    }
};
