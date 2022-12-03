class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size();
        int m = trainers.size();
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        
        int res = 0;
        int i = 0, j = 0;
        
        while (j < m && i < n) {
            if (players[i] <= trainers[j]) {
                res++;
                i++;
                j++;
            } else {
                j++;
            }
        }
        
        return res;
    }
};