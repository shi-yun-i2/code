#include <bits/stdc++.h>

using namespace std;

class MyStack1 {
public:
    queue<int> qa;
    queue<int> qb;

    MyStack1() {

    }

    void push(int x) {
        qa.push(x);
    }

    int pop() {
        // 留下最后一个元素输出
        while (qa.size() > 1) {
            qb.push(qa.front());
            qa.pop();
        }
        int res = qa.front();
        qa.pop();
        // 把qb的值全部推入qa
        while (!qb.empty()) {
            qa.push(qb.front());
            qb.pop();
        }
        return res;
    }

    int top() {
        while (qa.size() > 1) {
            qb.push(qa.front());
            qa.pop();
        }
        // 获取最后一个元素,然后加入qb,最后原封不动推回qa
        int res = qa.front();
        qb.push(res);
        qa.pop();
        while (!qb.empty()) {
            qa.push(qb.front());
            qb.pop();
        }
        return res;
    }

    bool empty() {
        return qa.empty() && qb.empty();
    }
};

class MyStack2 {
public:
    queue<int> qa;
    queue<int> qb;

    MyStack2() {

    }

    void push(int x) {
        qa.push(x);
    }

    int pop() {
        while (qa.size() > 1) {
            qb.push(qa.front());
            qa.pop();
        }
        int res = qa.front();
        qa.pop();
        // 直接赋值操作
        // 在 C++ 中，对于类对象，赋值操作会调用赋值运算符重载函数（operator=）来执行赋值操作。
        // 对于标准库的容器类，包括队列（std::queue），赋值操作会复制源容器中的元素到目标容器中。
        // 因此，qa = qb; 的语句会复制队列 qb 中的元素到队列 qa 中，使得 qa 和 qb 中的内容相同。
        // 这是一种深拷贝操作，两个队列之间互不影响。
        qa = qb;
        // 清空qb
        while (!qb.empty()) {
            qb.pop();
        }
        return res;
    }

    int top() {
        return qa.back();
    }

    bool empty() {
        return qa.empty() && qb.empty();
    }
};

class MyStack {
public:
    queue<int> q;

    MyStack() {

    }

    void push(int x) {
        q.push(x);
    }

    // 把队首元素插入到队尾
    int pop() {
        int size = q.size();
        size--;
        while (size--) {
            q.push(q.front());
            q.pop();
        }
        int res = q.front();
        q.pop();
        return res;
    }

    int top() {
        return q.back();
    }

    bool empty() {
        return q.empty();
    }
};