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
    bool traversal(TreeNode* root, int count) {
        if (root->left == nullptr && root->right == nullptr && count == 0) {
            return true;
        }
        if (root->left == nullptr && root->right == nullptr && count != 0) {
            return false;
        }
        if (root->left) {
            if (traversal(root->left, count - root->left->val)) {
                return true;
            }
        }
        if (root->right) {
            if (traversal(root->right, count - root->right->val)) {
                return true;
            }
        }
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        return traversal(root, targetSum - root->val);
    }
};

class Solution2 {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right && sum == root->val) {
            return true;
        }
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        stack<pair<TreeNode*, int>> st;
        if (root == nullptr) {
            return 0;
        }
        st.push({root, root->val});
        while (!st.empty()) {
            pair<TreeNode*, int> node = st.top();
            st.pop();
            if (node.first->left == nullptr && node.first->right == nullptr && node.second == sum) {
                return true;
            }
            if (node.first->right) {
                st.push({node.first->right, node.second + node.first->right->val});
            }
            if (node.first->left) {
                st.push({node.first->left, node.second + node.first->left->val});
            }
        }
        return false;
    }
};