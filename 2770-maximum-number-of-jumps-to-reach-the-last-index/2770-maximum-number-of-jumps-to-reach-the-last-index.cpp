class Solution {
public:
int n;
vector<int> dp;
     int dfs(int i, int target, vector<int> &nums) {
        if(i == n-1) {
            return dp[i] = 0;
        }
        if(dp[i] != INT_MIN) {
            return dp[i];
        }
         int ans = INT_MIN;
          for(int j = i+1; j < n; j++) {
            if(abs(nums[i] - nums[j]) <= target) {
                int take = 1 + dfs(j, target, nums);
                ans = max(ans, take);
            }
        }
         return dp[i] = ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();
        dp.assign(n+1, INT_MIN);
          int ans = dfs(0, target, nums);
            return ans < 0 ? -1 : ans;
    }
};