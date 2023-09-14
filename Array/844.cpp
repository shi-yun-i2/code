#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // 重构字符串
        string a = "", b = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '#') {
                a += s[i];
            } else {
                if (a != "") {
                    a.pop_back();
                }
            }
        }

        for (int i = 0; i < t.size(); i++) {
            if (t[i] != '#') {
                b += t[i];
            } else {
                if (b != "") {
                    b.pop_back();
                }
            }
        }
        // 字符串内容的比较可以直接使用==判断
        return a == b;
    }
};