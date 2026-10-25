class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {

        int n = nums.size();

        int leftEven = 0;
        int leftOdd = 0;
        int rightEven = 0;
        int rightOdd = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                rightEven += nums[i];
            else
                rightOdd += nums[i];
        }

        for (int i = 0; i < n; i++) {

            if (i % 2 == 0)
                rightEven -= nums[i];
            else
                rightOdd -= nums[i];

            int newEven = leftEven + rightOdd;
            int newOdd = leftOdd + rightEven;

            if (newOdd == newEven)
                ans++;

            if (i % 2 == 0)
                leftEven += nums[i];
            else
                leftOdd += nums[i];
        }

        return ans;
    }
};