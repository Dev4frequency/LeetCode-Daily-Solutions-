class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 0;
        long long totalSum = 0, currentSum = 0;
        for (int i : nums) {
            totalSum += i;
        }
        int difference = INT_MAX;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            currentSum += nums[i];
            long long left = currentSum / (i + 1);
            long long right =
                (i == n - 1) ? 0 : (totalSum - currentSum) / (n - i - 1);

            int currentDifference = abs(left - right);
            if (currentDifference < difference) {
                difference = currentDifference;
                ans = i;
            }
        }
        return ans;
    }
};