class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int, unordered_set<int>> dp;
        for (int stone : stones) {
            dp[stone] = unordered_set<int>();
        }
        
        dp[0].insert(0);
        for (int i = 0; i < n; ++i) {
            for (int jump : dp[stones[i]]) {
                for (int nextJump = jump - 1; nextJump <= jump + 1; ++nextJump) {
                    if (nextJump > 0 && dp.find(stones[i] + nextJump) != dp.end()) {
                        dp[stones[i] + nextJump].insert(nextJump);
                    }
                }
            }
        }
        
        return !dp[stones[n - 1]].empty();
    }
};