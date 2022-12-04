class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int cnt = 0;
        int prod = 1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i]) prod *= nums[i];
            else cnt++;
        }
        vector<int> answer;
        for (int i = 0; i < n; i++) {
            if (nums[i]) {
                if (cnt) {
                    answer.push_back(0);
                } else {
                    answer.push_back(prod / nums[i]);
                }
            } else {
                if (cnt - 1) {
                    answer.push_back(0);
                } else {
                    answer.push_back(prod);
                }
            }
        }
        return answer;
    }
};