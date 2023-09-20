#include <bits/stdc++.h>

using namespace std;

class MyQueue {
public:
    // 直接使用成员变量
    stack<int> stin;
    stack<int> stout;

    MyQueue() {

    }

    // 直接压入输入栈
    void push(int x) {
        stin.push(x);
    }

    // 如果输出栈为空,把输出栈全部导入
    int pop() {
        if (stout.empty()) {
            while (!stin.empty()) {
                stout.push(stin.top());
                stin.pop();
            }
        }
        int res = stout.top();
        stout.pop();
        return res;
    }

    // 复用pop()函数,重新压栈
    int peek() {
        int res = pop();
        stout.push(res);
        return res;
    }

    // 两栈为空表示队列为空
    bool empty() {
        return stin.empty() && stout.empty();
    }
};