class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long n = nums.size();        
        vector<long long> p(n);
        p[0] = nums[0];
        for (int i = 1; i < n; i++) p[i] = p[i - 1] + nums[i];
        long long res = INT_MAX;
        long long req;
        for (int i = 0; i < n; i++) {
            long long x, y;
            if (i == n - 1) {
                x = p[i] / (i + 1);
                y = 0;
                if (res > abs(x - y)) {
                    res = abs(x - y);
                    req = i;
                }
                continue;
            }
            x = p[i] /(i + 1);
            y = (p[n - 1] - p[i]) / (n - i - 1);
            if (res > abs(x - y)) {
                res = abs(x - y);
                req = i;
            }
        }
        return req;
    }
};