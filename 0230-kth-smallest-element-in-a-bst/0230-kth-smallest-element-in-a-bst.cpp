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
    vector<int> v;
    void flush() {
        v.clear();
    }
    void inorder(TreeNode* root) {
        if (root->left) inorder(root->left);
        v.push_back(root->val);
        if (root->right) inorder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        flush();
        inorder(root);
        return v[k - 1];
    }
};