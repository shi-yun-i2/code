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
    int getHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = getHeight(root->left);
        if (left == -1) {
            return -1;
        }
        int right = getHeight(root->right);
        if (right == -1) {
            return -1;
        }
        return abs(left - right) > 1 ? -1 : 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        return getHeight(root) == -1 ? false : true;
    }
};


class Solution2 {
public:
    // 返回以root为根节点的高度,即最大深度
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

    bool isBalanced(TreeNode* root) {
        queue<TreeNode*> q;
        if (root == nullptr) {
            return true;
        }
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (abs(maxDepth(node->left) - maxDepth(node->right)) > 1) {
                return false;
            }
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        return true;
    }

};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        stack<TreeNode*> st;
        if (root == nullptr) {
            return 0;
        }
        st.push(root);
        int depth = 0;
        int res = -1;
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if (node != nullptr) {
                st.push(node);
                st.push(nullptr);

                depth++;

                if (node->right) {
                    st.push(node->right);
                }
                if (node->left) {
                    st.push(node->left);
                }
            } else {
                st.pop();
                depth--;
            }
            res = max(res, depth);
        }
        return res;
    }

    bool isBalanced(TreeNode* root) {
        queue<TreeNode*> q;
        if (root == nullptr) {
            return true;
        }
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (abs(maxDepth(node->left) - maxDepth(node->right)) > 1) {
                return false;
            }
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        return true;
    }
};