class Solution {
public:
    int INF = 1e9;
    int numSquares(int n) {
        
        vector<int> isPS(n + 1, false);
        vector<int> PerSqr;
        for (int i = 1; i * i <= n; i++) {
            isPS[i * i] = true;
            PerSqr.push_back(i * i);
        }
        
        vector<int> dp(n + 1, INF);
        dp[0] = 0;
        dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            if (isPS[i]) dp[i] = 1;
            else {
                for (auto e : PerSqr) {
                    if (e > i) break;
                    else dp[i] = min(dp[i], dp[i - e] + 1);
                }    
            }
        }
        
        return dp[n];
    }
};