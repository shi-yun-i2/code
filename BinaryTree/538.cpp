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
    int pre = 0;

    void traversal(TreeNode* cur) {
        if (cur == nullptr) {
            return;
        }
        traversal(cur->right);
        cur->val += pre;
        pre = cur->val;
        traversal(cur->left);
    }

    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        traversal(root);
        return root;
    }
};

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int pre = 0;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur != nullptr || !st.empty()) {
            if (cur != nullptr) {
                st.push(cur);
                // 右中左
                cur = cur->right;
            } else {
                cur = st.top();
                st.pop();
                cur->val += pre;
                pre = cur->val;
                cur = cur->left;
            }
        }
        return root;
    }
};