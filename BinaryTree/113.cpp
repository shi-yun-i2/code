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

struct node {
    vector<int> path;
    TreeNode* final;
    int sum;
};

class Solution1 {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        stack<node> st;
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        vector<int> temp;
        temp.push_back(root->val);
        st.push({temp, root, root->val});
        while (!st.empty()) {
            node node = st.top();
            st.pop();

            if (node.final->left == nullptr && node.final->right == nullptr && node.sum == targetSum) {
                res.push_back(node.path);
                continue;
            }

            if (node.final->right) {
                vector<int> temp1 = node.path;
                temp1.push_back(node.final->right->val);
                st.push({temp1, node.final->right, node.sum + node.final->right->val});
            }
            if (node.final->left) {
                vector<int> temp2 = node.path;
                temp2.push_back(node.final->left->val);
                st.push({temp2, node.final->left, node.sum + node.final->left->val});
            }
        }
        return res;
    }
};


class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    // 主函数要对部分变量进行初始化
    void traversal(TreeNode* root, int count) {
        if (root->left == nullptr && root->right == nullptr && count == 0) {
            res.push_back(path);
            return;
        }
        if (root->left == nullptr && root->right == nullptr && count != 0) {
            return;
        }
        if (root->left) {
            path.push_back(root->left->val);
            traversal(root->left, count - root->left->val);
            path.pop_back();
        }
        if (root->right) {
            path.push_back(root->right->val);
            traversal(root->right, count - root->right->val);
            path.pop_back();
        }
        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return res;
        }
        // 把根节点放入路径
        path.push_back(root->val);
        traversal(root, targetSum - root->val);
        return res;
    }
};

