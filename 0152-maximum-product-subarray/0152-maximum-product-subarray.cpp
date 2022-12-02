class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<vector<int>> dp(n, vector<int>(2));
        
        dp[0] = {nums[0], nums[0]};
        
        int res = dp[0][1];
        
        for (int i = 1; i < n; i++) {
            dp[i][1] = max(dp[i - 1][0] * nums[i], dp[i - 1][1] * nums[i]);
            dp[i][0] = min(dp[i - 1][0] * nums[i], dp[i - 1][1] * nums[i]);       
            dp[i][1] = max(dp[i][1], nums[i]);
            dp[i][0] = min(dp[i][0], nums[i]);
            res = max(res, dp[i][1]);
        }
        return res;
    }
};