class Solution {
public:
    int subarrraysWithKDistinctLess(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int count = 0;
        map<int, int> mpp;
        if (k == 0) return 0;
        while (right < nums.size()) {
            mpp[nums[right]]++;
            while (mpp.size() > k) {
                mpp[nums[left]]--;
                if (mpp[nums[left]] == 0) mpp.erase(nums[left]);
                left++;
            }
            count = count + right - left + 1;
            right++;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarrraysWithKDistinctLess(nums, k) - subarrraysWithKDistinctLess(nums, k - 1);
    }
};