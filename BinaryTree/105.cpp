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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.size() == 0) {
            return nullptr;
        }
        int rootValue = preorder[0];
        TreeNode* root = new TreeNode(rootValue);
        if (inorder.size() == 1) {
            return root;
        }
        int index;
        for (index = 0; index < inorder.size(); index++) {
            if (inorder[index] == rootValue) {
                break;
            }
        }

        vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
        vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());

        preorder.erase(preorder.begin());

        vector<int> leftPreorder(preorder.begin(), preorder.begin() + leftInorder.size());
        vector<int> rightPreorder(preorder.begin() + leftInorder.size(), preorder.end());

        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);
        return root;
    }
};

class Solution {
public:
    TreeNode* traversal(vector<int>& preorder, int preorderBegin, int preorderEnd,
                        vector<int>& inorder, int inorderBegin, int inorderEnd) {
        if (inorderEnd == inorderBegin) {
            return nullptr;
        }
        int rootValue = preorder[preorderBegin];
        TreeNode* root = new TreeNode(rootValue);
        if (inorderEnd - inorderBegin == 1) {
            return root;
        }
        int index;
        for (index = inorderBegin; index < inorderEnd; index++) {
            if (inorder[index] == rootValue) {
                break;
            }
        }

        int leftInorderBegin = inorderBegin;
        int leftInorderEnd = index;

        int rightInorderBegin = index + 1;
        int rightInorderEnd = inorderEnd;

        int leftPreorderBegin = preorderBegin + 1;
        int leftPreorderEnd = preorderBegin + 1 + leftInorderEnd - leftInorderBegin;

        int rightPreorderBegin = preorderBegin + 1 + leftInorderEnd - leftInorderBegin;
        int rightPreorderEnd = preorderEnd;

        root->left = traversal(preorder, leftPreorderBegin, leftPreorderEnd, inorder, leftInorderBegin, leftInorderEnd);
        root->right = traversal(preorder, rightPreorderBegin, rightPreorderEnd, inorder, rightInorderBegin,
                                rightInorderEnd);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.size() == 0) {
            return nullptr;
        }
        TreeNode* root = traversal(preorder, 0, preorder.size(), inorder, 0, inorder.size());
        return root;
    }
};