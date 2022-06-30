class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<pair<bool, long long>> dp(n, {false, 1e10});  
        dp[0] = {true, 0};
        // for (int i = 1; i < n; i++) {
        //     for (int k = i - 1; k >= 0; k--) {
        //         if (dp[k].first) {
        //             int req = i - k;
        //             if (nums[k] >= req) {
        //                 dp[i].second = min(dp[i].second, dp[k].second + 1);
        //                 dp[i].first = true;
        //             }
        //         }
        //     }
        // }
        
        for (int i = 0; i < n; i++) {
            if (dp[i].first) {
                for (int j = 1; j <= nums[i]; j++) {
                    if (i + j < n) {
                        dp[i + j].first = true;
                        dp[i + j].second = min(dp[i + j].second, dp[i].second + 1);
                    }
                }
            }
        }
        return dp[n - 1].second;
    }
};