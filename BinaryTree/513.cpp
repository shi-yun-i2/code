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
    int maxDepth = -1;
    int result = 0;

    void traversal(TreeNode* root, int depth) {
        if (root->left == nullptr && root->right == nullptr) {
            if (depth > maxDepth) {
                maxDepth = depth;
                result = root->val;
            }
            return;
        }
        if (root->left) {
            traversal(root->left, depth + 1);
        }
        if (root->right) {
            traversal(root->right, depth + 1);
        }
    }

    int findBottomLeftValue(TreeNode* root) {
        traversal(root, 1);
        return result;
    }
};

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        if (root != nullptr) {
            q.push(root);
        }
        int res = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 1; i <= size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (i == 1) {
                    res = node->val;
                }
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return res;
    }
};