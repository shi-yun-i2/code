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
    ListNode* removeElements(ListNode* head, int val) {
        // 虚拟头节点
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* cur = dummyHead;
        // 短路与避免空指针运算
        while (cur != nullptr && cur->next != nullptr) {
            if (cur->next->val == val) {
                ListNode* temp = cur->next;
                // 已经改变了下一个元素,不需要cur++,否则会跳过下个一元素,应该继续检查下一个元素
                cur->next = cur->next->next;
                // 释放内存
                delete temp;
            } else {
                // 没有变动的情况下cur++
                cur = cur->next;
            }
        }
        ListNode* res = dummyHead->next;
        delete dummyHead;
        return res;
    }
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 循环移动头节点位置并释放内存
        while (head != nullptr && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        // head值为val的已经全部被删除,走正常逻辑
        ListNode* cur = head;
        while (cur != nullptr && cur->next != nullptr) {
            if (cur->next->val == val) {
                ListNode* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};
