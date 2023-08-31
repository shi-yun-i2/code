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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root != nullptr) {
            q.push(root);
        }
        while (!q.empty()) {
            int size = q.size();
            vector<int> v;
            for (int i = 1; i <= size; i++) {
                TreeNode* node = q.front();
                q.pop();
                v.push_back(node->val);
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            res.push_back(v);
        }
        return res;
    }
};

class Solution {
public:
    void order(TreeNode* root, vector<vector<int>> &res, int depth) {
        if (root == nullptr) {
            return;
        }
        if (res.size() == depth) {
            res.push_back(vector<int>());
        }
        res[depth].push_back(root->val);
        order(root->left, res, depth + 1);
        order(root->right, res, depth + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        int depth = 0;
        order(root, res, depth);
        return res;
    }
};
