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
    TreeNode* buildTree(vector<int>& nums, int begin, int end) {
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

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) {
            return nullptr;
        }
        TreeNode* root = buildTree(nums, 0, nums.size() - 1);
        return root;
    }
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(0);
        queue<TreeNode*> nodeQ;
        queue<int> leftQ;
        queue<int> rightQ;

        nodeQ.push(root);
        leftQ.push(0);
        rightQ.push(nums.size() - 1);

        while (!nodeQ.empty()) {
            TreeNode* cur = nodeQ.front();
            nodeQ.pop();
            int left = leftQ.front();
            leftQ.pop();
            int right = rightQ.front();
            rightQ.pop();
            int mid = (left + right) / 2;
            cur->val = nums[mid];

            if (left <= mid - 1) {
                cur->left = new TreeNode(0);
                nodeQ.push(cur->left);
                leftQ.push(left);
                rightQ.push(mid - 1);
            }

            if (right >= mid + 1) {
                cur->right = new TreeNode(0);
                nodeQ.push(cur->right);
                leftQ.push(mid + 1);
                rightQ.push(right);
            }
        }
        return root;
    }
};