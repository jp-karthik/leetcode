class Solution {
public:
    static bool cmp(pair<int, char> a, pair<int, char> b) {
        if (a.first > b.first) return true;
        else return false;
    }
    string frequencySort(string s) {
     
        map<char, int> m;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            m[s[i]]++;
        }
        
        vector<pair<int, char>> v;
        for (auto e : m) {
            v.push_back({e.second, e.first});
        }
        sort(v.begin(), v.end(), cmp);
        
        string res = "";
        for (auto e : v) {
            for (int i = 0; i < e.first; i++) {
                res += e.second;
            }
        }
        cout << res << endl;
        return res;
    }
};