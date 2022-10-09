class Solution {
public:
    string robotWithString(string s) {
        
        vector<int> v(26, 0);
        
        for (auto c : s) v[c - 97]++;
        
        string res = "";
        
        deque<char> S;
        deque<char> T;
        
        for (auto c : s) {
            S.push_back(c);
        }
        
        int minChar = 0;
        for (int i = 0; i < 26; i++) {
            if (v[i]) {
                minChar = i;
                break;
            }
        }
        
        while (S.size()) {
            
            char front = S.front();
            
            if (front - 97 == minChar) {
                res.push_back(front);
            } else {
                T.push_back(front);
            }
            
            S.pop_front();
            
            v[front - 97]--;
            
            while (minChar < 26 && v[minChar] == 0) {
                    minChar++;
            }
            
            while (T.size() && T.back() - 97 <= minChar) {
                res.push_back(T.back());
                T.pop_back();
            }
        }
        
        while (T.size()) {
            char back = T.back();
            res.push_back(back);
            T.pop_back();
        }
        
        return res;
    }
};