class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> M;
        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            M[temp].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for (auto e : M) {
            res.push_back(e.second);
        }
        return res;
    }
};