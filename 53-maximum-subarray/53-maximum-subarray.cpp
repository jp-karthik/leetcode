class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long INF = 1e18;
        vector<long long> dp(nums.size(), -INF);
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], (long long) nums[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};