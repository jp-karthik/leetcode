class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> v(26, false);
        
        for (int i = 0; i < sentence.size(); i++) {
            v[sentence[i] - 'a'] = true;
        }
        
        if (count(v.begin(), v.end(), true) == 26) return true;
        else return false;
    }
};