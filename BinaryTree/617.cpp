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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) return root2;
        if (root2 == nullptr) return root1;
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) return root2;
        if (root2 == nullptr) return root1;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root1);
        q2.push(root2);
        while (!q1.empty()) {
            TreeNode* node1 = q1.front();
            q1.pop();
            TreeNode* node2 = q2.front();
            q2.pop();
            node1->val += node2->val;

            if (node1->left != nullptr && node2->left != nullptr) {
                q1.push(node1->left);
                q2.push(node2->left);
            }

            if (node1->right != nullptr && node2->right != nullptr) {
                q1.push(node1->right);
                q2.push(node2->right);
            }

            if (node1->left == nullptr && node2->left != nullptr) {
                node1->left = node2->left;
            }

            if (node1->right == nullptr && node2->right != nullptr) {
                node1->right = node2->right;
            }
        }
        return root1;
    }
};