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

    bool isValidBST(TreeNode* root) {
        traversal(root);
        if (res.size() <= 1) {
            return true;
        }
        for (int i = 1; i < res.size(); i++) {
            if (res[i] <= res[i - 1]) {
                return false;
            }
        }
        return true;
    }
};

class Solution2 {
public:
    long maxx = LONG_MIN;

    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        bool left = isValidBST(root->left);
        if (root->val > maxx) {
            maxx = root->val;
        } else {
            return false;
        }
        bool right = isValidBST(root->right);
        return left && right;
    }

};

class Solution {
public:
    TreeNode* pre = nullptr;

    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        bool left = isValidBST(root->left);

        if (pre != nullptr && pre->val >= root->val) return false;
        pre = root;

        bool right = isValidBST(root->right);
        return left && right;
    }
};
