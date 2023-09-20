#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                count++;
            }
        }
        int pre = s.size() - 1;
        // 避免重新申请内存,直接resize
        s.resize(s.size() + count * 2);
        int back = s.size() - 1;

        // 从后向前填充元素，避免了从前向后填充元素时，每次添加元素都要将添加元素之后的所有元素向后移动的问题
        while (pre >= 0) {
            if (s[pre] != ' ') {
                s[back--] = s[pre];
            } else {
                s[back--] = '0';
                s[back--] = '2';
                s[back--] = '%';
            }
            pre--;
        }
        // 最后pre和back同时等于-1
        return s;
    }
};