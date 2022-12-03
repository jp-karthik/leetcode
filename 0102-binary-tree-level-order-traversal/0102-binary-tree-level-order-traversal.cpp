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
    vector<vector<int>> v;
    void flush() {
        v.clear();        
    }
    
    int getDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int subAns = 0;
        if (root->left) subAns = max(subAns, getDepth(root->left));
        if (root->right) subAns = max(subAns, getDepth(root->right));
        return 1 + subAns;
    }
    
    void helper(TreeNode* root, int depth) {
        if (root) {
            v[depth].push_back(root->val);
            if (root->left) {
                helper(root->left, depth + 1);
            }
            if (root->right) {
                helper(root->right, depth + 1);
            }
        }
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        flush();
        v.resize(getDepth(root));
        helper(root, 0);
        return v;
    }
};