class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 1;
        int curr = 1;
        if (n == 0) return 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) continue;
            if (nums[i] + 1 == nums[i + 1]) {
                curr++;
                ans = max(ans, curr);
            } else {
                curr = 1;
            }
        }
        return ans;
    }
};