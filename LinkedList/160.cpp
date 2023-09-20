#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// set去重contains
class Solution1 {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int lenA = 0, lenB = 0;
        ListNode* curA = headA;
        ListNode* curB = headB;
        while (curA != nullptr) {
            lenA++;
            curA = curA->next;
        }
        while (curB != nullptr) {
            lenB++;
            curB = curB->next;
        }
        if (lenA > lenB) {
            curA = headA;
            curB = headB;
        } else {
            curA = headB;
            curB = headA;
        }
        int gap = abs(lenA - lenB);
        // 对齐末尾元素
        while (gap--) {
            curA = curA->next;
        }
        // 同步移动
        for (int i = 1; i <= min(lenA, lenB); i++) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }
};

class Solution {
public:
    // “如果走到尽头也没有找到你都踪影，那么我就换另一条路从头寻找” “我也一样。”
    // 设a,b不相交和相交的长度推算相交节点
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* pa = headA;
        ListNode* pb = headB;
        while (pa != pb) {
            pa = (pa == nullptr) ? headB : pa->next;
            pb = (pb == nullptr) ? headA : pb->next;
        }
        return pa;
    }
};