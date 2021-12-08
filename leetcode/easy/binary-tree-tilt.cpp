/*
 * https://leetcode.com/problems/binary-tree-tilt/
 */

#include <cstdlib>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int findTilt(TreeNode* root) {
        if (root == NULL)
            return (0);

        int sumTilt;

        sumTilt = std::abs(totalVal(root->left) - totalVal(root->right));
        if (root->left)
            sumTilt += findTilt(root->left);
        if (root->right)
            sumTilt += findTilt(root->right);
        return (sumTilt);
    }
private:
    int totalVal(TreeNode *root) {
        if (root == NULL)
            return (0);

        int total = root->val;

        total += totalVal(root->left);
        total += totalVal(root->right);
        return (total);
    }
};
