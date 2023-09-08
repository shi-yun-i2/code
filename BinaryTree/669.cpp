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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val < low) {
            return trimBST(root->right, low, high);
        }
        if (root->val > high) {
            return trimBST(root->left, low, high);
        }
        // root的val值在区间内
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};


class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return nullptr;
        }
        while (root != nullptr && (root->val < low || root->val > high)) {
            if (root->val < low) {
                root = root->right;
            }
            if (root->val > high) {
                root = root->left;
            }
        }
        TreeNode* cur = root;
        while (cur != nullptr) {
            while (cur->left && cur->left->val < low) {
                cur->left = cur->left->right;
            }
            cur = cur->left;
        }
        cur = root;
        while (cur != nullptr) {
            while (cur->right && cur->right->val > high) {
                cur->right = cur->right->left;
            }
            cur = cur->right;
        }
        return root;
    }
};