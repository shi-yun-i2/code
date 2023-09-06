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
    TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (postorder.size() == 0) {
            return nullptr;
        }
        int rootValue = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootValue);
        if (postorder.size() == 1) {
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

        postorder.resize(postorder.size() - 1);

        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        root->left = buildTree(leftInorder, leftPostorder);
        root->right = buildTree(rightInorder, rightPostorder);
        return root;
    }
};

class Solution {
public:
    TreeNode* traversal(vector<int> &inorder, int inorderBegin, int inorderEnd, vector<int> &postorder,
                        int postorderBegin, int postorderEnd) {
        if (postorderBegin == postorderEnd) {
            return nullptr;
        }
        int rootValue = postorder[postorderEnd - 1];
        TreeNode* root = new TreeNode(rootValue);
        if (postorderEnd - postorderBegin == 1) {
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

        int leftPostorderBegin = postorderBegin;
        int leftPostorderEnd = postorderBegin + (leftInorderEnd - leftInorderBegin);

        int rightPostorderBegin = postorderBegin + (leftInorderEnd - leftInorderBegin);
        int rightPostorderEnd = postorderEnd - 1;

        root->left = traversal(inorder,leftInorderBegin,leftInorderEnd,postorder,leftPostorderBegin,leftPostorderEnd);
        root->right = traversal(inorder,rightInorderBegin,rightInorderEnd,postorder,rightPostorderBegin,rightPostorderEnd);
        return root;
    }

    TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (postorder.size() == 0) {
            return nullptr;
        }
        TreeNode* root = traversal(inorder, 0, inorder.size(), postorder, 0, postorder.size());
        return root;
    }
};