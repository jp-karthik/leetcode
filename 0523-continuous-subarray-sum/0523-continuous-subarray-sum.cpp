class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<long long> p(n);
        p[0] = nums[0];
        for (int i = 1; i < n; i++) {
            p[i] = p[i - 1] + nums[i];
        }
        
        for (int i = 0; i < n; i++) {
            p[i] %= k;
            if (i > 0 && p[i] == 0) {
                return true;
            }
        }
      
        
        unordered_map<int, vector<int>> m;
        
        for (int i = 0; i < n; i++) {
            m[p[i]].push_back(i);
        }
        
        for (auto e : m) {
            if (e.second.size() > 2) {
                return true;
            }
        }
        
        for (auto e : m) {
            if (e.second.size() == 2) {
                if (abs(e.second[1] - e.second[0]) > 1) {
                    return true;
                }
            }
        }
        
        return false;
    }
};