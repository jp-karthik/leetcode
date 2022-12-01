class Solution {
public:
    bool isVowel(char c) {
        if (c == 'A' || c == 'A' + 32) return true;
        if (c == 'E' || c == 'E' + 32) return true;
        if (c == 'I' || c == 'I' + 32) return true;
        if (c == 'O' || c == 'O' + 32) return true;
        if (c == 'U' || c == 'U' + 32) return true;
        return false;
    }
    bool halvesAreAlike(string s) {
        int x = 0;
        int y = 0;
        for (int i = 0; i < s.length() / 2; i++) {
            if (isVowel(s[i])) x++;
        }
        for (int i = s.length() / 2; i < s.length(); i++) {
            if (isVowel(s[i])) y++;
        }
        if (x == y) return true;
        else return false;
    }
};