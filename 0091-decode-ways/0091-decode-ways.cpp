class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (s[0] == '0') {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        
        vector<long long> dp(n);
        dp[0] = 1;
        int val = stoi(s.substr(0, 2));
        if (s[1] != '0') {
            dp[1] = 1;
        }
        if (val <= 26) dp[1]++;
        for (int i = 2; i < n; i++) {
            int val = stoi(s.substr(i - 1, 2));
            if (val % 10 == 0) {
                if (s[i] == '0' && s[i - 1] == '0') {
                    dp[i] = 0;
                    continue;
                }
                if (s[i - 1] <= '2') {
                    dp[i] += dp[i - 2];
                } else {
                    dp[i] = 0;
                }
            } else {
                dp[i] += dp[i - 1];
                if (val <= 26 && s[i - 1] != '0') dp[i] += dp[i - 2];
            }
        }
        
        return dp[n - 1];
    }
};