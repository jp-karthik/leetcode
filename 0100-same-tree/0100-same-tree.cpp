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
    bool isLeaf(TreeNode* root) {
        if (!root->left && !root->right) return true;
        else return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        } 
        if (!p) return false;
        if (!q) return false;
        
        if (isLeaf(p) && isLeaf(q)) {
            if (p->val == q->val) return true;
            else return false;
        } 
        
        if (isLeaf(p)) return false;
        if (isLeaf(q)) return false;
        
        if (p->left && !q->left) return false;
        if (!p->left && q->left) return false;
        if (p->right && !q->right) return false;
        if (!p->right && q->right) return false;
        
        if (p->val == q->val) {
            bool res = true;
            if (p->left) res = res && isSameTree(p->left, q->left);
            if (p->right) res = res && isSameTree(p->right, q->right);
            return res;
        } else return false;
    }
};