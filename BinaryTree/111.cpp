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

class Solution {
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
