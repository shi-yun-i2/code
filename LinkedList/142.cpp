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
    ListNode* detectCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        // 有环一定能找到
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                ListNode* pa = head;
                ListNode* pb = fast;
                while (pa != pb) {
                    pa = pa->next;
                    pb = pb->next;
                }
                return pa;
            }
        }
        // 没环返回空指针
        return nullptr;
    }
};