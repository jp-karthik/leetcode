class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        for (int i = 0; i < m; i++) {
            if (matrix[n - 1][i] == '1') {
                dp[n - 1][i] = 1;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (matrix[i][m - 1] == '1') {
                dp[i][m - 1] = 1;
            }
        }
        
        for (int i = n - 2; i >= 0; i--) {
            for (int j = m - 2; j >= 0; j--) {
                if (matrix[i][j] == '0') {
                    dp[i][j] = 0;
                    continue;
                }
                bool c = matrix[i][j + 1] == '1' && matrix[i + 1][j] == '1' && matrix[i + 1][j + 1] == '1';
                if (c) dp[i][j] = min(dp[i + 1][j + 1], min(dp[i + 1][j], dp[i][j + 1])) + 1;
                else dp[i][j] = 1;
            }
        }
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res = max(res, dp[i][j]);
            }
        }
        
        res *= res;
        return res;
    }
};