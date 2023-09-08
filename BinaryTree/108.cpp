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
    TreeNode* buildTree(vector<int> &nums, int begin, int end) {
        if (begin > end) {
            return nullptr;
        }
        int mid = (begin + end) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        if (end == begin) {
            return root;
        }
        root->left = buildTree(nums, begin, mid - 1);
        root->right = buildTree(nums, mid + 1, end);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int> &nums) {
        if (nums.size() == 0) {
            return nullptr;
        }
        TreeNode* root = buildTree(nums, 0, nums.size() - 1);
        return root;
    }
};