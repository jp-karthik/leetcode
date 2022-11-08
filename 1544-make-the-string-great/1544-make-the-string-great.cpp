class Solution {
public:    
    string makeGood(string s) {
        int i = 0;
        for (; i < (int) s.length() - 1;) {
            if (abs(s[i + 1] - s[i]) == 32) {
                auto it1 = s.begin() + i;
                s.erase(it1);
                it1 = s.begin() + i;
                s.erase(it1);
                
                if (i > 0) {
                    i--;
                }
                
            } else {
                i++;
            }
        }
        return s;
    }
};