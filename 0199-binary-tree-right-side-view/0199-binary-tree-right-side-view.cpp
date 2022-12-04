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
    vector<int> rv;
    set<int> d;
    void helper(TreeNode* root, int depth) {
        if (root) {
            if (!d.count(depth)) {
                rv.push_back(root->val);
                d.insert(depth);
            }
            if (root->right) {
                helper(root->right, depth + 1);                
            }
            if (root->left) {
                helper(root->left, depth + 1);
            }
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        helper(root, 0);
        return rv;
    }
};