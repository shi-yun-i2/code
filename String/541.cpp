#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    string reverseStr(string s, int k) {
        // 当需要固定规律一段一段去处理字符串的时候，在for循环的表达式上做变化
        for (int i = 0; i < s.size(); i += 2 * k) {
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k);
            } else {
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size(), pos = 0;
        while (pos < n) {
            if (pos + k <= n) {
                // reverse左闭右开,end()指向最后一个元素的下一个位置
                reverse(s.begin() + pos, s.begin() + pos + k);
            } else {
                reverse(s.begin() + pos, s.end());
            }
            pos += 2 * k;
        }
        return s;
    }
};