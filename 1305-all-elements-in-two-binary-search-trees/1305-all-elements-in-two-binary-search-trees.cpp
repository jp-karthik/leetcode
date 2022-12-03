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
    void populate(TreeNode* root) {
        if (root == NULL) return;
        v.push_back(root->val);
        if (root->left) populate(root->left);
        if (root->right) populate(root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        flush();
        populate(root1);
        populate(root2);
        sort(v.begin(), v.end());
        return v;
    }
};