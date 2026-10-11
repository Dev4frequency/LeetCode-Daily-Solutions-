class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        int n = nums.size();

        for (int window = l; window <= r; window++) {
            if (window > n) break; 

            int sum = 0;
            for (int i = 0; i < window; i++) {
                sum += nums[i];
            }
            if (sum > 0) ans = min(ans, sum);

            for (int i = window; i < n; i++) {
                sum += nums[i];        
                sum -= nums[i - window]; 
                if (sum > 0) ans = min(ans, sum);
            }
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};