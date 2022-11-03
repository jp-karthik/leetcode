class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> m;
        
        for (string& e : words) {
            m[e]++;
        }
        
        int res = 0;
        bool middle = false;
        
        for (auto e : m) {
            if (e.first[0] == e.first[1]) {
                res += e.second;
                if (e.second % 2)  {
                    middle = true;
                    res--;
                }
                m.erase(e.first);
            } else if (e.first[0] < e.first[1]) {
                string rev = "";
                rev += e.first[1];
                rev += e.first[0];
                res += min(e.second, m[rev]) * 2;
                m.erase(rev);
                m.erase(e.first);
            }
        }
        
        if (middle) res++;
        
        return 2 * res;
    }
};