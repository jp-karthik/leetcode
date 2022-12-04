class Solution {
public:
    bool isPalindrome(string s) {
        string x = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                x += 'a' - 'A' + s[i];
            } else if (s[i] >= 'a' && s[i] <= 'z') {
                x += s[i];
            } else if (s[i] >= '0' && s[i] <= '9') {
                x += s[i];
            }
        }
        int n = x.length();
        for (int i = 0; i < n / 2;  i++) {
            if (x[i] != x[n - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};