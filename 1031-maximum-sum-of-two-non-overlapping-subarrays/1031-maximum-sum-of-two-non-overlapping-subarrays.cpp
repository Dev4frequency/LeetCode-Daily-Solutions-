class Solution {
public:
    vector<int> maxWindow(vector<int>& nums, int lBound, int uBound,
                          int wSize) {
        int wStart = lBound, wEnd = lBound + wSize;
        if (wEnd > uBound) {
            return {-1, -1, 0};
        }
        int currentSum =
            accumulate(nums.begin() + wStart, nums.begin() + wEnd, 0);
        int maxSum = currentSum, mLow = wStart, mHigh = wEnd;

        while (wEnd < uBound) {
            if (maxSum < currentSum) {
                maxSum = currentSum;
                mLow = wStart;
                mHigh = wEnd;
            }
            currentSum += -nums[wStart++] + nums[wEnd++];
        }

        return {mLow, mHigh, maxSum};
    }

    int solve(vector<int>& nums, int fw, int sw) {
        int low = 0, high = sw;
        int sw_sum = accumulate(nums.begin() + low, nums.begin() + high, 0);
        int maxSum = 0;

        while (high < nums.size()) {            
            auto f_left = maxWindow(nums, 0, low, fw);
            auto f_right = maxWindow(nums, high, nums.size(), fw);

            maxSum = max(maxSum, sw_sum + max(f_left[2], f_right[2]));
            sw_sum += -nums[low++] + nums[high++];
        }

        auto f_left = maxWindow(nums, 0, low, fw);
        return max(maxSum, sw_sum + f_left[2]);
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(solve(nums, firstLen, secondLen), solve(nums, secondLen, firstLen));
    }
};