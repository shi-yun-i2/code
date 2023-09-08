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
    map<int, int> mapp;

    void traversal(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        traversal(root->left);
        mapp[root->val]++;
        traversal(root->right);
    }

    static bool cmp(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        traversal(root);
        vector<pair<int, int>> v(mapp.begin(), mapp.end());
        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < v.size(); i++) {
            if (v[i].second == v[0].second) {
                res.push_back(v[i].first);
            }
        }
        return res;
    }
};


class Solution2 {
public:
    int maxCount = -1;
    int count = 0;
    TreeNode* pre = nullptr;
    vector<int> res;

    void traversal(TreeNode* cur) {
        if (cur == nullptr) {
            return;
        }
        traversal(cur->left);
        if (pre == nullptr) {
            count = 1;
        } else if (pre->val == cur->val) {
            count++;
        } else {
            count = 1;
        }
        pre = cur;
        if (count == maxCount) {
            res.push_back(cur->val);
        }
        if (count > maxCount) {
            maxCount = count;
            res.clear();
            res.push_back(cur->val);
        }
        traversal(cur->right);
    }

    vector<int> findMode(TreeNode* root) {
        if (root == nullptr) {
            return res;
        }
        traversal(root);
        return res;
    }
};

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        int maxCount = 0;
        int count = 0;
        vector<int> res;
        while (!st.empty() || cur != nullptr) {
            if (cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top();
                st.pop();
                if (pre == nullptr) {
                    count = 1;
                } else if (pre->val == cur->val) {
                    count++;
                } else {
                    count = 1;
                }
                if (count == maxCount) {
                    res.push_back(cur->val);
                }
                if (count > maxCount) {
                    maxCount = count;
                    res.clear();
                    res.push_back(cur->val);
                }
                pre = cur;
                cur = cur->right;
            }
        }
        return res;
    }
};