class Solution {
public:
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        unordered_map<int, int> mpp;
        for (auto it : targetIndices)
            mpp[it]++;
        int n = source.size(), m = pattern.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return helper(n, m, source, pattern, mpp, dp);
    }
    int helper(int i, int j, string& s, string& p, unordered_map<int, int>& mpp,
               vector<vector<int>>& dp) {
        if (i == 0) {
            if (j == 0)
                return 0;
            return -1e8;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int res = helper(i - 1, j, s, p, mpp, dp);
        if (j > 0 && s[i - 1] == p[j - 1])
            res = max(res, helper(i - 1, j - 1, s, p, mpp, dp));
        if (mpp.count(i - 1))
            res = max(res, 1 + helper(i - 1, j, s, p, mpp, dp));
        return dp[i][j] = res;
    }
};