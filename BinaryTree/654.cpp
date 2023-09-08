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
    TreeNode* constructMaximumBinaryTree(vector<int> &nums) {
        if (nums.size() == 0) {
            return nullptr;
        }
        int index = 0;
        int maxx = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxx) {
                index = i;
                maxx = nums[i];
            }
        }

        int rootValue = nums[index];
        TreeNode* root = new TreeNode(rootValue);

        if (nums.size() == 1) {
            return root;
        }

        vector<int> left(nums.begin(), nums.begin() + index);
        vector<int> right(nums.begin() + index + 1, nums.end());

        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);
        return root;
    }
};

class Solution {
public:
    TreeNode* traversal(vector<int> &nums, int start, int end) {
        if (start == end) {
            return nullptr;
        }
        int index = 0;
        int maxx = -1;
        for (int i = start; i < end; i++) {
            if (nums[i] > maxx) {
                maxx = nums[i];
                index = i;
            }
        }
        int rootValue = nums[index];
        TreeNode* root = new TreeNode(rootValue);
        if (start - end == 1) {
            return root;
        }

        int leftBegin = start;
        int leftEnd = index;

        int rightBegin = index + 1;
        int rightEnd = end;

        root->left = traversal(nums, leftBegin, leftEnd);
        root->right = traversal(nums, rightBegin, rightEnd);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int> &nums) {
        if (nums.size() == 0) {
            return nullptr;
        }
        TreeNode* root = traversal(nums, 0, nums.size());
        return root;
    }
};