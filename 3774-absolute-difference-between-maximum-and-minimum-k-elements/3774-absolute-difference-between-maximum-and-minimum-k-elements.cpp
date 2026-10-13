class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int small = 0, large = 0;
        for(int i = 0; i < k; i++) {
            small += nums[i];
            large += nums[n - 1 - i];
        }

        return large - small;
    }
};