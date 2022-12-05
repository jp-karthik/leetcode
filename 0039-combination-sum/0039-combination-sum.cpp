class Solution {
public:
    vector<vector<int>> res;
    void f(vector<int>& candidates, int i, int target, vector<int>& soFar) {
        if (target == 0) {
            res.push_back(soFar);
            return;
        }
        if (i == candidates.size()) return;
        if (candidates[i] <= target) {
            soFar.push_back(candidates[i]);
            f(candidates, i, target - candidates[i], soFar);
            soFar.pop_back();
        }
        f(candidates, i + 1, target, soFar);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> soFar = {};
        f(candidates, 0, target, soFar);
        return res;
    }
};