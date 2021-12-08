/*
 * https://leetcode.com/problems/house-robber-iii/
 */
#include <algorithm>
#include <utility>
using namespace std;

/* Definition for a binary tree node. */
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
    int rob(TreeNode* root) {
        pair<int, int> res = crossRob(root);
        return (max(res.first, res.second));
    }

private:
    pair<int, int> crossRob(TreeNode *root)
    {
        pair<int, int> res, left, right;

        if (root == NULL)
            return (res);

        left = crossRob(root->left);
        right = crossRob(root->right);

        /* first: skip root's house, second: rob root's house */
        res.first += max(left.first, left.second);
        res.first += max(right.first, right.second);
        res.second += root->val;
        res.second += left.first + right.first;

        return (res);
    }
};
