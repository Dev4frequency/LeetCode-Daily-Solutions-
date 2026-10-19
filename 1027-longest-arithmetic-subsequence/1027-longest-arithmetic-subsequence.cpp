class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 2;

        unordered_map<int, unordered_map<int, int>> dp;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = nums[i] - nums[j];
                if (dp[j].count(diff)) {
                    int prevLen = dp[j][diff];
                    dp[i][diff] = prevLen + 1;
                    maxLen = max(maxLen, dp[i][diff]);
                } else {
                    dp[i][diff] = 2;
                }
            }
        }

        return maxLen;
    }
};