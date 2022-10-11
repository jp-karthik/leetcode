class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pref = "";
        int i = 0;
        while (1) {
            bool valid = true;
            for (auto s : strs) {
                if (i >= s.length()) {
                    valid = false;
                    break;
                }
            }
            if (!valid) break;
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != c) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                pref.push_back(c);
                i++;
            } else {
                break;
            }
        }
        return pref;
    }
};