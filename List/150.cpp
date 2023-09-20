#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& v) {
        // 注意:数据类型
        stack<long long> st;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == "+" || v[i] == "-" || v[i] == "*" || v[i] == "/") {
                long long num1 = st.top();
                st.pop();
                long long num2 = st.top();
                st.pop();
                if (v[i] == "+") st.push(num2 + num1);
                if (v[i] == "-") st.push(num2 - num1);
                if (v[i] == "*") st.push(num2 * num1);
                if (v[i] == "/") st.push(num2 / num1);
            } else {
                // 使用stoll将字符串转化为long long类型整数
                st.push(stoll(v[i]));
            }
        }
        // 答案最后被压入栈中
        long long res = st.top();
        st.pop();
        return res;
    }
};