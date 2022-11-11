class Solution {
public:
    string removeDuplicates(string s) {
        string res = "";
        for (auto c : s) {
            res.push_back(c);
            while (res.size() >= 2 && res.back() == res[res.size() - 2]) {
                res.pop_back();
                res.pop_back();
            }
        }
        return res;
    }
};