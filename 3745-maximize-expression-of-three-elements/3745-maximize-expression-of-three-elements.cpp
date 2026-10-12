class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int n = nums.size();
        int maxi1 = nums[0];
        int maxi2 = nums[1];
        int mini = nums[n-1];

        return maxi1 + maxi2 - mini;
    }
};