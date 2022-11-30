class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        for (auto& e : arr) {
            m[e]++;
        }
        vector<int> f;
        for (auto& e : m) {
            f.push_back(e.second);
        }
        sort(f.begin(), f.end());
        for (int i = 0; i < f.size() - 1; i++) {
            if (f[i] == f[i + 1]) {
                return false;
            }
        }
        return true;
    }
};