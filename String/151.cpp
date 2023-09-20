#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void removeSpace(string& s) {
        int slow = 0;
        for (int i = 0; i < s.size(); i++) {
            // 去除全部空格
            if (s[i] != ' ') {
                // 除了首项,每次添加单词先添加一个空格
                if (slow != 0) {
                    s[slow++] = ' ';
                }
                // 遇到字母,循环读取字母直到为空格为止
                while (i < s.size() && s[i] != ' ') {
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow);
    }

    string reverseWords(string s) {
        // 传入的是引用,直接返回对象s
        removeSpace(s);
        reverse(s.begin(), s.end());
        int start = 0;
        for (int i = 0; i < s.size(); i++) {
            // 遇到空格翻转字符串
            if (s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
            if (i == s.size() - 1) {
                reverse(s.begin() + start, s.end());
            }
        }
        return s;
    }
};
