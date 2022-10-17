class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int INF = 1e7;
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INF));
        for (int j = 1; j <= amount; j++) {
            dp[0][j] = INF;
        }
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i - 1]) {
                    dp[i][j] = min(dp[i][j], 1 + dp[i][j - coins[i - 1]]);
                }
            }
        }
        if (dp[n][amount] == INF) return -1;
        else return dp[n][amount];
    }
};