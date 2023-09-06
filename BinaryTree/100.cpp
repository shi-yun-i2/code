#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution1 {
public:
    bool isSameTree(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right != nullptr) {
            return false;
        } else if (left != nullptr && right == nullptr) {
            return false;
        } else if (left == nullptr && right == nullptr) {
            return true;
        } else if (left->val != right->val) {
            return false;
        } else {
            return isSameTree(left->left, right->left) && isSameTree(left->right, right->right);
        }
    }
};

class Solution {
public:
    bool isSameTree(TreeNode* left, TreeNode* right) {
        queue<TreeNode*> q;
        q.push(left);
        q.push(right);
        while (!q.empty()) {
            TreeNode* l = q.front();
            q.pop();
            TreeNode* r = q.front();
            q.pop();
            if (l == nullptr && r != nullptr) {
                return false;
            } else if (l != nullptr && r == nullptr) {
                return false;
            } else if (l == nullptr && r == nullptr) {
                //都是空指针需要继续下一次循环
                continue;
            } else if (l->val != r->val) {
                return false;
            }
            q.push(l->left);
            q.push(r->left);
            q.push(l->right);
            q.push(r->right);
        }
        return true;
    }
};
