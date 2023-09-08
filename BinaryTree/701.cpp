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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        if (root->val > val) {
            root->left = insertIntoBST(root->left, val);
        }
        if (root->val < val) {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};

class Solution2 {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            root = new TreeNode(val);
            return root;
        }
        TreeNode* pre = nullptr;
        TreeNode* cur = root;
        while (cur) {
            pre = cur;
            if (cur->val > val) {
                cur = cur->left;
            } else if (cur->val < val) {
                cur = cur->right;
            }
        }
        TreeNode* node = new TreeNode(val);
        if (pre->val > val) {
            pre->left = node;
        } else {
            pre->right = node;
        }
        return root;
    }
};

class Solution {
public:
    TreeNode* pre = nullptr;

    void traversal(TreeNode* cur, int val) {
        if (cur == nullptr) {
            TreeNode* node = new TreeNode(val);
            if (pre->val > val) {
                pre->left = node;
            } else {
                pre->right = node;
            }
            return;
        }
        // 遍历之前得到pre
        pre = cur;
        if (cur->val > val) {
            traversal(cur->left, val);
        }
        if (cur->val < val) {
            traversal(cur->right, val);
        }
        return;
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            root = new TreeNode(val);
            return root;
        }
        traversal(root,val);
        return root;
    }
};