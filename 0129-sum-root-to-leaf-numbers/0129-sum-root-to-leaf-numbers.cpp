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
    int res = 0;    
    bool isLeaf(TreeNode* node) {
        if (!node->left && !node->right) return true;
        else return false;
    }
    void helper(TreeNode* root, string soFar) { 
        if (isLeaf(root)) {
            soFar += (char) (root->val + 48);
            res += stoi(soFar);
            return;
        }
        soFar += (char) (root->val + 48);
        if (root->left) {
            helper(root->left, soFar);
        }
        if (root->right) {
            helper(root->right, soFar);
        }
    }
    int sumNumbers(TreeNode* root) {
        helper(root, "");
        return res;
    }
};