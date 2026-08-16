class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        int n = nums.size();
        long long result = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] < 0) continue;
            
            long long currentSum = nums[i];
            for (int j = 2; ; ++j) {
                int index = (i + 1) * j * j - 1;
                if (index >= n) break;
                currentSum += nums[index];
                nums[index] = -1;
            }

            result = max(result, currentSum);
        }

        return result;
    }
};