#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (st.empty() || s[i] != st.top()) {
                st.push(s[i]);
            } else {
                st.pop();
            }
        }
        string res = "";
        while (!st.empty()) {
            // 栈中出来的元素相对于插入的顺序会反向
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};

class Solution {
public:
    string removeDuplicates(string s) {
        // 使用string作为char类型的栈,支持push和pop操作,都是从末尾,相当于栈顶
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            // 字符串的back是右边
            if (res.empty() || s[i] != res.back()) {
                res.push_back(s[i]);
            } else {
                res.pop_back();
            }
        }
        return res;
    }
};

