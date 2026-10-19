class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        const int INF = 1e9;
        vector<int> dp(time + 1, INF);
        dp[0] = 0;
        for (int t = 1; t <= time; ++t) {
            for (auto& clip : clips) {
                int start = clip[0], end = clip[1];
                if (start <= t && t <= end) {
                    dp[t] = min(dp[t], dp[start] + 1);
                }
            }
        }
        return dp[time] == INF ? -1 : dp[time];
    }
};