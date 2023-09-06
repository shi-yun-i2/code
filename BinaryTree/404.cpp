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
    int sum = 0;

    void getSum(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
            sum += root->left->val;
        }
        getSum(root->left);
        getSum(root->right);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        getSum(root);
        return sum;
    }
};

class Solution2 {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftSum = 0, rightSum = 0;
        bool flag = false;
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
            leftSum = root->left->val;
            flag = true;
        }
        rightSum = sumOfLeftLeaves(root->right);
        if (!flag) {
            leftSum = sumOfLeftLeaves(root->left);
        }
        return leftSum + rightSum;
    }
};


class Solution3 {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftSum = sumOfLeftLeaves(root->left);
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
            leftSum = root->left->val;
        }
        int rightSum = sumOfLeftLeaves(root->right);
        return leftSum + rightSum;
    }
};

class Solution4 {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        stack<TreeNode*> st;
        if (root == nullptr) {
            return 0;
        }
        st.push(root);
        int sum = 0;
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if (node->left != nullptr && node->left->left == nullptr && node->left->right == nullptr) {
                sum += node->left->val;
            }
            if (node->right) {
                st.push(node->right);
            }
            if (node->left) {
                st.push(node->left);
            }
        }
        return sum;
    }
};

class Solution5 {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        queue<TreeNode*> q;
        if (root == nullptr) {
            return 0;
        }
        q.push(root);
        int sum = 0;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left != nullptr && node->left->left == nullptr && node->left->right == nullptr) {
                sum += node->left->val;
            }
            if (node->right) {
                q.push(node->right);
            }
            if (node->left) {
                q.push(node->left);
            }
        }
        return sum;
    }
};

class Solution {
public:
    bool isLeafNode(TreeNode* root) {
        return !root->left && !root->right;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        queue<TreeNode*> q;
        if (root == nullptr) {
            return 0;
        }
        q.push(root);
        int sum = 0;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                if (isLeafNode(node->left)) {
                    sum += node->left->val;
                } else {
                    q.push(node->left);
                }
            }
            if (node->right) {
                if (!isLeafNode(node->right)) {
                    q.push(node->right);
                }
            }
        }
        return sum;
    }
};