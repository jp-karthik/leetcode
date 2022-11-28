class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        set<int> M;
        map<int,int> W;
        map<int,int> L;
        
        for (auto& match : matches) {
            int x = match[0];
            int y = match[1];
            M.insert(x);
            M.insert(y);
            W[x]++;
            L[y]++;
        }
        
        vector<vector<int>> RES(2);
        
        for (auto& x : M) {
            if (L[x] == 0) {
                RES[0].push_back(x);     
                continue;
            }
            if (L[x]  == 1) {
                RES[1].push_back(x);
            }
        }
        
        return RES;
    }
};