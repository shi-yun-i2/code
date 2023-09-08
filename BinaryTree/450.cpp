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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val == key) {
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }
            if (root->left == nullptr && root->right != nullptr) {
                return root->right;
            } else if (root->left != nullptr && root->right == nullptr) {
                return root->left;
            } else {
                TreeNode* cur = root;
                cur = cur->right;
                while (cur->left) {
                    cur = cur->left;
                }
                cur->left = root->left;
                TreeNode* node = root->right;
                delete root;
                return node;
            }
        }
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};

class Solution2 {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val == key) {
            if (root->right == nullptr) {
                return root->left;
            }
            TreeNode* cur = root->right;
            while (cur->left) {
                cur = cur->left;
            }
            swap(root->val, cur->val);
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }
};

class Solution {
public:
    TreeNode* deleteOneNode(TreeNode* node) {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->right == nullptr) {
            return node->left;
        }
        TreeNode* cur = node->right;
        while (cur->left) {
            cur = cur->left;
        }
        cur->left = node->left;
        return node->right;
    }

    TreeNode* deleteNode(TreeNode* root, int val) {
        if (root == nullptr) {
            return root;
        }
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        while (cur) {
            if (cur->val == val) {
                break;
            }
            pre = cur;
            if (cur->val > val) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        if (pre == nullptr) {
            return deleteOneNode(cur);
        }
        if (pre->left && pre->left->val == val) {
            pre->left = deleteOneNode(cur);
        }
        if (pre->right && pre->right->val == val) {
            pre->right = deleteOneNode(cur);
        }
        return root;
    }
};