class Solution {
public:
    int minDifficulty(vector<int>& v, int d) {
        int n = v.size();
        if (n < d) return -1;
        
        long long INF = 1e18;
        vector<vector<long long>> dp(n + 1, vector<long long>(d + 1, INF));
        
        dp[0][0] = 0; // zero days and zero tasks
        
        for (int j = 1; j <= d; j++) { // i = 0
            dp[0][j] = INF;
        }
        
        for (int i = 1; i <= n; i++) { // j = 0
            dp[i][0] = INF;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= d; j++) {
                //dp[i][j]
                for (int k = 0; k < i; k++) {
                    long long mx = 0;
                    for (int x = k; x < i; x++) {
                        mx = max(mx, (long long) v[x]);
                    }
                    dp[i][j] = min(dp[i][j], dp[k][j - 1] + mx);
                }
            }
        }
        
        return dp[n][d];
    }
};