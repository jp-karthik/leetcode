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
    vector<string> res;
    bool isLeaf(TreeNode * node) {
        if (!node->left && !node->right) {
            return true;
        } else return false;
    }
    void dfs(TreeNode* root, string& s) {
        int len = to_string(root->val).length();
        s += to_string(root->val);
        if (isLeaf(root)) {
            res.push_back(s);
        }
        if (root->left) {
            s += "->";
            dfs(root->left, s);
            s.pop_back();
            s.pop_back();
        } 
        if (root->right) {
            s += "->";
            dfs(root->right, s);
            s.pop_back();
            s.pop_back();
        }
        for (int i = 0; i < len; i++) {
            s.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL) return {};
        string s = "";
        dfs(root, s);
        return res;
    }
};