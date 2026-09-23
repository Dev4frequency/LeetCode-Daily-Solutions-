class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int diff = accumulate(nums.begin(), nums.end(), 0) - x;
        int n = nums.size();

        if(diff < 0)
        return -1;
        if(diff == 0)
        return n;

        int left = 0, right = 0, currsum = 0, longest = INT_MIN;

        while(right < n){ 
            currsum += nums[right];

            while(currsum > diff && left <= right)
            currsum -= nums[left++];

            if(currsum == diff)
            longest = max(longest, right - left + 1);

            right++;
        }
        if(longest == INT_MIN)
        return -1;

        return n - longest;
    }
};