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
    map<TreeNode*, int> dp;
    
    bool isLeaf(TreeNode* node) {
        if (!node->left && !node->right) return true;
        else return false;
    }
    
    void helper(TreeNode* root) {
        if (isLeaf(root)) {
            dp[root] = root->val;
            return;
        }
        
        if (root->left) {
            helper(root->left);
        }
        if (root->right) {
            helper(root->right);
        }
        
        int curr = root->val;
        int l = 0;
        int r = 0;
        if (root->left) l = max(l, dp[root->left]);
        if (root->right) r = max(r, dp[root->right]);

        curr = curr + max(l, r);
        dp[root] = curr;

        return;
    }
    
    int get(TreeNode* root) {
        int subl = -1e8;
        int subr = -1e8;
        
        if (root->left) subl = max(subl, get(root->left));
        if (root->right) subr = max(subr, get(root->right));
        
        int curr = root->val;
        int l = 0;
        int r = 0;
        if (root->left) l = max(l, dp[root->left]);
        if (root->right) r = max(r, dp[root->right]);
        
        curr += l + r;
    
        return max(curr, max(subl, subr));    
    }
    
    int maxPathSum(TreeNode* root) {
        dp.clear();
        helper(root);
        return get(root);
    }
};