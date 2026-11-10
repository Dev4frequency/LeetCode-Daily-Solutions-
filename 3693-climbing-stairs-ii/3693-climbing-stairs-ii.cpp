class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, -1);
        dp[1] = costs[0] + 1;

        auto minCost = [&](this auto &&minCost, int i) {
            if (i == 0) return 0;
            if (i == 1) return dp[1];
            if (i == 2) return dp[2] = min(dp[1] + costs[1] + 1, costs[1] + 4);
            
            int& res = dp[i];
            if (res != -1) return res;
            return res = min(min(minCost(i-1) + costs[i-1] + 1,
                                     minCost(i-2) + costs[i-1] + 4),
                                     minCost(i-3) + costs[i-1] + 9);
        };
        return minCost(n);
    }  
};