class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + stoneValue[i];
        auto sum = [&](int i, int j) { return pre[j + 1] - pre[i]; };
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                int best = 0;
                for (int k = i; k < j; k++) {
                    int left = sum(i, k), right = sum(k + 1, j);
                    if (left < right) best = max(best, left + dp[i][k]);
                    else if (left > right) best = max(best, right + dp[k + 1][j]);
                    else best = max(best, max(left + dp[i][k], right + dp[k + 1][j]));
                }
                dp[i][j] = best;
            }
        }
        return dp[0][n - 1];
    }
};