class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        long long INF = 1e16;
        long long left = INF;
        long long mid = INF;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (left != INF && mid != INF) {
                if (nums[i] > mid) {
                    return true;
                }
            }
            if (nums[i] < left) {
                left = nums[i];
            }
            if (nums[i] > left && nums[i] < mid) {
                mid = nums[i];
            }
        }
        return false;
    }
};