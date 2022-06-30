class Solution {
public:
    bool canJump(vector<int>& nums) {
        int idx = nums.size() - 1;
        while (idx > 0) {
            bool valid = false;
            for (int k = idx - 1; k >= 0; k--) {
                int dist = idx - k;
                if (nums[k] >= dist) {
                    idx = k;
                    valid = true;
                    break;
                }
            }
            if (valid) continue;
            return false;
        }
        return true;
    }
};