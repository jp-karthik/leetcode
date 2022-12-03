class Solution {
public:
    int getDigitSum(int num) {
        int res = 0;
        while (num) {
            res += num % 10;
            num /= 10;
        }
        return res;
    }
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        map<int, vector<int>> m;
        for (int i = 0; i < n; i++) {
            m[getDigitSum(nums[i])].push_back(nums[i]);
        }
        int res = -1;
        for (auto& e : m) {
            vector<int>& v = e.second;
            if (v.size() > 1) {
                sort(v.begin(), v.end());
                int len = v.size();
                res = max(res, v[len - 1] + v[len - 2]);
            }
        }
        return res;
        return -1;
    }
};