/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int cnt = 0;
    void helper(TreeNode* root, int val) {
        if (root->val >= val) cnt++;
        if (root->left) helper(root->left, max(val, root->val));
        if (root->right) helper(root->right, max(val, root->val));
    }
    int goodNodes(TreeNode* root) {
        helper(root, -1e4 - 1);
        return cnt;
    }
};