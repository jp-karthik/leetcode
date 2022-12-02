class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        set<char> a;
        set<char> b;
        map<char, int> f1;
        map<char, int> f2;
        
        // O(N * log(N))
        for (char& c : word1) {
            a.insert(c);
            f1[c]++;
        }
        for (char& c : word2) {
            b.insert(c);
            f2[c]++;
        }
        
        // O(N * log(N))
        if (a != b) return false;

        // O(N * log(N))
        vector<int> x;
        vector<int> y;
        for (pair<char, int> p : f1) {
            x.push_back(p.second);
        }
        for (pair<char, int> p : f2) {
            y.push_back(p.second);
        }
        
        // O(N * log(N))
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        
        int len = x.size();
        for (int i = 0; i < len; i++) {
            if (x[i] != y[i]) return false;
        }
        return true;
    }
};