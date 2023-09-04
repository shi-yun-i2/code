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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        if (root != nullptr) {
            q.push(root);
        }
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            swap(node->left, node->right);
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
        return root;
    }
};

class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

class Solution3 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            swap(node->left, node->right);
            if (node->right != nullptr) {
                st.push(node->right);
            }
            if (node->left != nullptr) {
                st.push(node->left);
            }
        }
        return root;
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> st;
        if (root != nullptr) {
            st.push(root);
        }
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if (node != nullptr) {
                if (node->right != nullptr) {
                    st.push(node->right);
                }
                if (node->left != nullptr) {
                    st.push(node->left);
                }
                st.push(node);
                st.push(nullptr);
            } else {
                node = st.top();
                st.pop();
                swap(node->left, node->right);
            }
        }
        return root;
    }
};








