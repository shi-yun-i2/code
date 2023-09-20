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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* cur = dummyHead;
        // 要交换的两个节点不能有空节点
        while (cur != nullptr && cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* back1 = cur->next;
            ListNode* back2 = cur->next->next;
            ListNode* back3 = cur->next->next->next;
            cur->next = back2;
            back2->next = back1;
            back1->next = back3;
            // cur永远在两个交换节点的前一个节点
            cur = cur->next->next;
        }
        ListNode* res = dummyHead->next;
        delete dummyHead;
        return res;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // 只有单个节点时需要返回不为空的那一个节点
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* front = head;
        ListNode* back = head->next;
        // 后面传过来的节点用前面的next指接住
        ListNode* temp = swapPairs(back->next);
        // 翻转链表
        back->next = front;
        front->next = temp;
        return back;
    }
};