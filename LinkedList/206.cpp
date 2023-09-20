#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        // 记录改变后无法访问但需要使用的节点
        ListNode* back;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            back = cur->next;
            cur->next = pre;
            // 注意赋值的顺序,pre要用到cur节点,所以在前面赋值
            pre = cur;
            cur = back;
        }
        return pre;
    }
};

class Solution {
public:
    ListNode* reverse(ListNode* pre, ListNode* cur) {
        // 终止条件
        if (cur == nullptr) {
            // 返回头节点
            return pre;
        }
        ListNode* temp = cur->next;
        cur->next = pre;
        // 递归返回头节点,递归赋值
        return reverse(cur, temp);
    }

    ListNode* reverseList(ListNode* head) {
        return reverse(nullptr, head);
    }
};