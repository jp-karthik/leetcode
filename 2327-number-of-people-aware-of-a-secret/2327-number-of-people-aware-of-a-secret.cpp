class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n + 1);
        dp[1] = 1;
        long long mod = 1e9 + 7;
        
        for (int i = 2; i <= n; i++) {
            int s = i - delay;
            int e = i - forget + 1;
            for (int j = s; j >= 0 && j >= i - forget + 1; j--) {
                dp[i] += dp[j];
            }
            dp[i] %= mod;
        }
        long long res = 0;
        for (int i = n; i >= n - forget + 1; i--) {
            res += dp[i];
        }
        res %= mod;
        return res;
    }
};