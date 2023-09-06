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
    int minDepth(TreeNode* root) {
        int depth = 0;
        queue<TreeNode*> q;
        if (root != nullptr) {
            q.push(root);
        }
        while (!q.empty()) {
            int size = q.size();
            // 先修改深度
            depth++;
            for (int i = 1; i <= size; i++) {
                TreeNode* node = q.front();
                // front之后出队
                q.pop();
                // 不是二选一关系
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
                if (node->left == nullptr && node->right == nullptr) {
                    return depth;
                }
            }
        }
        return depth;
    }
};

class Solution2 {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr && root->right != nullptr) {
            return 1 + minDepth(root->right);
        }
        if (root->left != nullptr && root->right == nullptr) {
            return 1 + minDepth(root->left);
        }
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

class Solution {
public:
    int res = 1e9;

    void getMinDepth(TreeNode* root, int depth) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            res = min(res, depth);
        }
        if (root->left != nullptr) {
            getMinDepth(root->left, depth + 1);
        }
        if (root->right != nullptr) {
            getMinDepth(root->right, depth + 1);
        }
    }

    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        getMinDepth(root, 1);
        return res;
    }
};