class Solution {
public:
    int dp[71][5000];

    int solve(vector<vector<int>>& mat, int& target, int sum, int row) {
        if (row == mat.size()) {
            return abs(target - sum);
        }
        if (dp[row][sum] != -1) {
            return dp[row][sum];
        }

        int ans = INT_MAX;
        for (int col = 0; col < mat[row].size(); col++) {
            int res = solve(mat, target, sum + mat[row][col], row + 1);
            ans = min(ans, res);
            if (ans == 0) break; 
        }
        return dp[row][sum] = ans;
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(mat, target, 0, 0);
    }
};