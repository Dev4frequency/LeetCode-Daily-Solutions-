class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end(), [](int a, int b) 
        {
            return abs(a) > abs(b);
        });
        for (int &num : nums) 
        {
            if (k > 0 && num < 0) 
            {
                num = -num;
                k--;
            }
        }
        int sum = 0;
        for (int num : nums) 
        {
            sum += num;
        }
        if (k % 2 == 1) 
        {
            sum -= 2 * abs(nums.back());
        }

        return sum;
    }
};