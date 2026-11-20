class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        vector <int> dp(1000003, 0);
        int ans = 1;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){
            int curr = nums[i];

            dp[curr + 1] = max(dp[curr + 1], dp[curr] + 1);
            if(dp[curr] == 0) dp[curr] = 1;
            dp[curr] = max(dp[curr], dp[curr - 1] + 1);
            ans = max({ans, dp[curr], dp[curr + 1]});
        }

        return ans;
    }
};