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

class Solution1 {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        int maxx = 0;
        for (int i = 0; i < root->children.size(); i++) {
            maxx = max(maxx, maxDepth(root->children[i]));
        }
        return maxx + 1;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
        queue<Node*> q;
        int depth = 0;
        if (root != nullptr) {
            q.push(root);
        }
        while (!q.empty()) {
            int size = q.size();
            depth++;
            for (int i = 1; i <= size; i++) {
                Node* node = q.front();
                q.pop();
                for (int j = 0; j < node->children.size(); j++) {
                    if (node->children[j] != nullptr) {
                        q.push(node->children[j]);
                    }
                }
            }
        }
        return depth;
    }
};
