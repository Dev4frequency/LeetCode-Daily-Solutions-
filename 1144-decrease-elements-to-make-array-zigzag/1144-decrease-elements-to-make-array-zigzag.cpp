class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums)
    {
        int n = nums.size();
        int count1 = 0, count2 = 0;
        for(int i=0; i<n; i+=2)
        {
            int left = (i > 0) ? nums[i-1] : INT_MAX;
            int right = (i+1 < n) ? nums[i+1] : INT_MAX;
            if(nums[i] >= min(left, right))
            {
                count1 += nums[i] - min(left, right) + 1;
            }
        }
        for(int i=1; i<n; i+=2)
        {
            int left = nums[i-1];
            int right = (i+1 < n) ? nums[i+1] : INT_MAX;
            if(nums[i] >= min(left, right))
            {
                count2 += nums[i] - min(left, right) + 1;
            }
        }
        return min(count1, count2);
    }
};