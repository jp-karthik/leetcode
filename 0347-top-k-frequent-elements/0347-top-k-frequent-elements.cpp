class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for (auto e : nums) {
            m[e]++;
        }
        vector<int> res;
        vector<pair<int, int>> v;
        for (auto e : m) v.push_back({e.second, e.first});
        sort(v.begin(), v.end());
        int cnt = 0;
        while (cnt < k) {
            res.push_back(v.back().second);
            v.pop_back();
            cnt++;
        }
        return res;
    }
};