#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        // 翻转前面
        reverse(s.begin(), s.begin() + n);
        // 翻转后面
        reverse(s.begin() + n, s.end());
        // 翻转全部
        reverse(s.begin(), s.end());
        return s;
    }
};
