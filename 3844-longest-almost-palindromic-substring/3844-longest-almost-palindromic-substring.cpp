class Solution {
public:
    int almostPalindromic(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n,1));

        // Fill LPS DP table
        for (int i = n-1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i+1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = (j-i == 1 ? 2 : dp[i+1][j-1] + 2);
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }

        int ans = 1;
        // Check all substrings for almost-palindrome
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                int len = j - i + 1;
                if(len - dp[i][j] <= 1) {
                    ans = max(ans, len);
                }
            }
        }

        return ans;
    }
};