class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<bool> p(n, false);
        int x = -1;
        int y = -1;
        for (int i = 0; i < n; i++) {
            if (p[nums[i]] == true) {
                x = nums[i];
                continue;
            }
            p[nums[i]] = true;
        }
        for (int i = 0; i < n; i++) {
            if (p[i + 1] == false) {
                y = i + 1;
                break;
            }
        }
        return {x, y};
    }
};