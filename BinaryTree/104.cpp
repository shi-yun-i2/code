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
    int maxDepth(TreeNode* root) {
        int depth = 0;
        queue<TreeNode*> q;
        if (root != nullptr) {
            q.push(root);
        }
        while (!q.empty()) {
            int size = q.size();
            depth++;
            for (int i = 1; i <= size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
        }
        return depth;
    }
};


class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

class Solution3 {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftMax = maxDepth(root->left);
        int rightMax = maxDepth(root->right);
        return 1 + max(leftMax, rightMax);
    }
};

class Solution {
public:
    int result;

    void getMaxDepth(TreeNode* root, int depth) {
        result = max(result, depth);
        if (root->left != nullptr) {
            getMaxDepth(root->left, depth + 1);
        }
        if (root->right != nullptr) {
            getMaxDepth(root->right, depth + 1);
        }
    }

    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        getMaxDepth(root, 1);
        return result;
    }
};