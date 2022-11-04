class Solution {
public:
    bool isV(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;        
        else return false;
    }
    
    string reverseVowels(string s) {
        int n = s.length();
        vector<char> v;
        for (auto c : s) {
            if (isV(c)) {
                v.push_back(c);
            }
        }
        reverse(v.begin(), v.end());
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (isV(s[i])) {
                s[i] = v[j];
                j++;
            }
        }
        return s;
    }
};