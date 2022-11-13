class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        int n = s.length();
        
        string st = "";
        
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                st += s[i];
            } else {
                if (st.length()) v.push_back(st);
                st = "";
            }
        }
        
        if (st.length()) v.push_back(st);
        
        int l = v.size();
        string res = "";
        
        for (int i = l - 1; i >= 0; i--) {
            if (i == 0) {
                res += v[i];
            } else {
                res += v[i];
                res += ' ';
            }
        }
        
        return res;
    }
};