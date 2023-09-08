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
    TreeNode* traversal(TreeNode* cur, TreeNode* p, TreeNode* q) {
        if (cur == nullptr) {
            return nullptr;
        }
        if (cur->val > p->val && cur->val > q->val) {
            TreeNode* left = traversal(cur->left, p, q);
            if (left != nullptr) {
                return left;
            }
        }
        if (cur->val < p->val && cur->val < q->val) {
            TreeNode* right = traversal(cur->right, p, q);
            if (right != nullptr) {
                return right;
            }
        }
        return cur;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return traversal(root, p, q);
    }
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root != nullptr) {
            if (root->val > p->val && root->val > q->val) {
                root = root->left;
            } else if (root->val < p->val && root->val < q->val) {
                root = root->right;
            } else {
                return root;
            }
        }
        return root;
    }
};