class Solution {
public:
    long long solve(int ind, vector<vector<int>>& rides,vector<long long>&dp) {
        if (ind == rides.size()) return 0;
        if(dp[ind]!=-1)return dp[ind];
        long long nottake = solve(ind+1, rides,dp);
        vector<int> temp = {rides[ind][1],0,0};
        int nextIndex = lower_bound(rides.begin()+ind, rides.end(), temp) - rides.begin();
        long long get = rides[ind][1] - rides[ind][0] + rides[ind][2];
        long long take = get + solve(nextIndex, rides,dp);
        return dp[ind] = max(take, nottake);
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end());
        vector<long long>dp(rides.size(),-1);
        return solve(0, rides,dp);
    }
};