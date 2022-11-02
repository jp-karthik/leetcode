class Solution {
public:
    set<string> vis;
    int INF = 1e8;
    
    int f(string& s, string& e, vector<string>& b) {
        if (s == e) return 0;
        int res = INF;
        vis.insert(s);
        for (auto u : b) {
            if (vis.count(u) == 0) {
                int diff = 0;
                for (int i = 0; i < 8; i++) {
                    if (s[i] != u[i]) {
                        diff++;
                    }
                }
                if (diff == 1) {
                    res = min(res, f(u, e, b) + 1);
                }
            }
        }
        vis.erase(s);
        return res;
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
        int result = f(start, end, bank);
        if (result == INF) return -1;
        else return result;
    }
};