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
    void traverse(TreeNode* root, vector<int>& path, vector<string>& result) {
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            string s;
            for (int i = 0; i < path.size() - 1; i++) {
                s = s + to_string(path[i]) + "->";
            }
            s = s + to_string(path[path.size() - 1]);
            result.push_back(s);
            return;
        }
        if (root->left) {
            traverse(root->left, path, result);
            path.pop_back();
        }
        if (root->right) {
            traverse(root->right, path, result);
            path.pop_back();
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> result;
        if (root == nullptr) {
            return result;
        }
        traverse(root, path, result);
        return result;
    }
};

class Solution2 {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        stack<TreeNode*> nodeSt;
        stack<string> pathSt;
        vector<string> result;
        if (root == nullptr) {
            return result;
        }
        nodeSt.push(root);
        pathSt.push(to_string(root->val));
        while (!nodeSt.empty()) {
            TreeNode* node = nodeSt.top();
            nodeSt.pop();
            string path = pathSt.top();
            pathSt.pop();
            if (node->left == nullptr && node->right == nullptr) {
                result.push_back(path);
                continue;
            }
            if (node->left) {
                // 每次插入节点,都会在另一个栈中插入对应的路径
                nodeSt.push(node->left);
                pathSt.push(path + "->" + to_string(node->left->val));
            }
            if (node->right) {
                nodeSt.push(node->right);
                pathSt.push(path + "->" + to_string(node->right->val));
            }
        }
        return result;
    }
};

class Solution3 {
public:
    void traverse(TreeNode* root, string path, vector<string>& res) {
        path += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            res.push_back(path);
            return;
        }
        if (root->left) {
            traverse(root->left, path + "->", res);
        }
        if (root->right) {
            traverse(root->right, path + "->", res);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == nullptr) {
            return res;
        }
        traverse(root, "", res);
        return res;
    }
};

class Solution {
public:
    void traverse(TreeNode* root, string path, vector<string>& res) {
        path += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            res.push_back(path);
            return;
        }
        if (root->left) {
            path += "->";
            traverse(root->left, path, res);
            path.pop_back();
            path.pop_back();
        }
        if (root->right) {
            path += "->";
            traverse(root->right, path, res);
            path.pop_back();
            path.pop_back();
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == nullptr) {
            return res;
        }
        traverse(root, "", res);
        return res;
    }
};
