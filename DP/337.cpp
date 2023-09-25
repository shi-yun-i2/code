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

class Solution {
public:
    // 数组第一项表示不偷,第二项表示偷,每个节点维护最大值
    vector<int> traversal(TreeNode* cur) {
        if (cur == nullptr) {
            return {0, 0};
        }
        vector<int> left = traversal(cur->left);
        vector<int> right = traversal(cur->right);
        int yes = cur->val + left[0] + right[0];
        // 左右孩子都可以选择偷或者不偷,哪个大选哪个
        int no = max(left[0], left[1]) + max(right[0], right[1]);
        return {no, yes};
    }

    int rob(TreeNode* root) {
        vector<int> v = traversal(root);
        return max(v[0], v[1]);
    }
};