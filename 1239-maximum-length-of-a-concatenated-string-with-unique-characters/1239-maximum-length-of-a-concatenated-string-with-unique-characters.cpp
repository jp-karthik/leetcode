class Solution {
public:
    map<char, int> m;
    
    bool isValid(string& s) {
        for (auto c : s) {
            if (m[c - 'a'] > 1) {
                return false;
            }
        }
        return true;
    }
    
    int backtrack(vector<string>& a, int i) {
        if (i == a.size()) {
            return 0;
        }    
        int res = 0;
        for (auto c : a[i]) {
            m[c - 'a']++;
        }
        if (isValid(a[i])) {
            int op1 = backtrack(a, i + 1) + a[i].length();
            res = max(res, op1); 
        }
        for (auto c : a[i]) {
            m[c - 'a']--;
        }
        int op2 = backtrack(a, i + 1);
        res = max(res, op2);
        return res;
    }
    
    int maxLength(vector<string>& arr) {
        for (int i = 0; i < 26; i++) {
            m[i] = 0;
        }
        return backtrack(arr, 0);
    }
    
};