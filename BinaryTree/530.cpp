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
    vector<int> res;

    void traversal(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        traversal(root->left);
        res.push_back(root->val);
        traversal(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        int minn = INT_MAX;
        traversal(root);
        for (int i = 1; i < res.size(); i++) {
            int temp = res[i] - res[i - 1];
            if (temp < minn) {
                minn = temp;
            }
        }
        return minn;
    }
};


class Solution2 {
public:
    int res = INT_MAX;
    TreeNode* pre = nullptr;

    void traversal(TreeNode* cur) {
        if (cur == nullptr) {
            return;
        }
        traversal(cur->left);
        if (pre != nullptr) {
            res = min(res, cur->val - pre->val);
        }
        pre = cur;
        traversal(cur->right);
    }

    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return res;
    }
};

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        int res = INT_MAX;
        while (!st.empty() || cur != nullptr) {
            if (cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top();
                st.pop();
                if (pre != nullptr) {
                    res = min(res, cur->val - pre->val);
                }
                pre = cur;
                cur = cur->right;
            }
        }
        return res;
    }
};