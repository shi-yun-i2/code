#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 左括号必须以正确的顺序闭合
    bool isValid(string s) {
        // 奇数
        if (s.size() & 1) {
            return false;
        }
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            // 推入反向括号方便做判断
            if (s[i] == '(') {
                st.push(')');
            } else if (s[i] == '[') {
                st.push(']');
            } else if (s[i] == '{') {
                st.push('}');
                // 遇到空栈或者不匹配时返回
            } else if (st.empty() || st.top() != s[i]) {
                return false;
            } else if (st.top() == s[i]) {
                st.pop();
            }
        }
        // 遍历完后空栈表示成功
        return st.empty();
    }
};
