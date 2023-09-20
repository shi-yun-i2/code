#include <bits/stdc++.h>

using namespace std;

class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode* next;

        ListNode(int val) : val(val), next(nullptr) {};

        ListNode(int val, ListNode* next) : val(val), next(next) {};
    };

    ListNode* dummyHead;
    int size;

    MyLinkedList() {
        // 统一操作
        dummyHead = new ListNode(0);
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }
        ListNode* cur = dummyHead;
        // 等于循环确定次数更清晰
        for (int i = 1; i <= index + 1; i++) {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) {
            return;
        }
        ListNode* cur = dummyHead;
        for (int i = 1; i <= index; i++) {
            cur = cur->next;
        }
        ListNode* node = new ListNode(val, cur->next);
        cur->next = node;
        size++;
    }

    void deleteAtIndex(int index) {
        // 注意边界条件
        if (index < 0 || index >= size) {
            return;
        }
        ListNode* cur = dummyHead;
        for (int i = 1; i <= index; i++) {
            cur = cur->next;
        }
        ListNode* temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        size--;
    }
};