#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    bool repeatedSubstringPattern(string s) {
        // 若字符串是 a + a 形式,拼接后是 a/ + a + a + a/,a/表示删除前后字符,中间形成了a + a原字符串形式
        // 若字符串是 a + a + a形式,拼接后是a/ + a + a + a + a + a/,中间形成了两个a + a + a原字符串形式
        string p = s;
        s = s + s;
        // 使用erase时先判断长度,避免非法内存访问
        if (s.size() > 0) {
            // erase的时间复杂度较高O(n)
            s.erase(s.begin());
        }

        if (s.size() > 0) {
            s.erase(s.end() - 1);
        }

        // string::npos指针表示没有找到(no position)
        if (s.find(p) == string::npos) {
            return false;
        }

        return true;
    }
};


class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        int next[len];
        next[0] = -1;
        for (int i = 1, j = -1; i < len; i++) {
            if (j > -1 && s[i] != s[j + 1]) {
                j = next[j];
            }
            if (s[i] == s[j + 1]) {
                j++;
            }
            next[i] = j;
        }

        // 如果等于-1表示字符串由自身重复一次形成,不符合题目的子串要求
        // (len - (next[len - 1] + 1))表示最小重复子串的长度(数组长度 - 最长公共前后缀长度)
        if (next[len - 1] != -1 && len % (len - (next[len - 1] + 1)) == 0) {
            return true;
        }
        return false;
    }
};