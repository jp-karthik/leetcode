class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
            } else {
                dp[i][i + 1] = false;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (abs(i - j) > 1) {
                    dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
                }
            }
        }
        int best = INT_MIN;
        int I, J;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (dp[i][j]) {
                    if (best < j - i + 1) {
                        best = j - i + 1;
                        I = i;
                        J = j;
                    }
                }
            }
        }
        return s.substr(I, J - I + 1);
    }
};