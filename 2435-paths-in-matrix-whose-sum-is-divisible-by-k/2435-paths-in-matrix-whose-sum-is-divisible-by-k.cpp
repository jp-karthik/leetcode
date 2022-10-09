class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        long long MOD = 1e9 + 7;
        // our solution is dp[n - 1][m - 1][0]
        
        long long dp[n][m][k]; 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int z = 0; z < k; z++) {
                    dp[i][j][z] = 0;
                }
            }
        }
        
        // base case
        for (int z = 0; z < k; z++) {
            if (grid[0][0] % k == z) {
                dp[0][0][z] = 1;
            }    
        }
        
        // general dp case
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) continue;               
                for (int z = 0; z < k; z++) {
                    // move from the top
                    if (i > 0) {
                        int prev = z - (grid[i][j] % k);
                        prev += k;
                        prev %= k;
                        dp[i][j][z] += dp[i - 1][j][prev];
                    }
                    // move from the left
                    if (j > 0) {
                        int prev = z - (grid[i][j] % k);
                        prev += k;
                        prev %= k;
                        dp[i][j][z] += dp[i][j - 1][prev];
                    }
                    dp[i][j][z] %= MOD;
                }
            }
        }
        
        return dp[n - 1][m - 1][0];
    }
};