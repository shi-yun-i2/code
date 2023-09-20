#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 统一删除操作
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;
        // 移动n + 1使slow到达被删除节点之前
        for (int i = 1; i <= n + 1; i++) {
            fast = fast->next;
        }
        // fast为空指针时slow是倒数第n + 1个元素
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        // 原来的head可能已经被delete了,需要返回dummyHead的下一个节点,是新的头节点
        ListNode* res = dummyHead->next;
        delete dummyHead;
        return res;
    }
};
