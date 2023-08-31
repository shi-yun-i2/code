#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        vector<vector<int>> res;
        if (root != nullptr) {
            q.push(root);
        }
        while (!q.empty()) {
            int size = q.size();
            vector<int> v;
            for (int i = 1; i <= size; i++) {
                Node* node = q.front();
                q.pop();
                v.push_back(node->val);
                for (Node* ele : node->children) {
                    if (ele != nullptr) {
                        q.push(ele);
                    }
                }
            }
            res.push_back(v);
        }
        return res;
    }
};