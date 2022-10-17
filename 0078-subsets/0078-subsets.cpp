class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>& ssf, vector<int>& nums, int i) {
        if (i == nums.size()) {
            res.push_back(ssf);
            return;
        }
        
        helper(ssf, nums, i + 1);
        
        ssf.push_back(nums[i]);
        helper(ssf, nums, i + 1);
        ssf.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        vector<int> s = {};
        helper(s, nums, 0);
        return res;
    }
};