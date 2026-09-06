class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int swaps = 0;
        while (left < right) {
            while (left < right && nums[left] != 0)
                left++; 
            while (left < right && nums[right] == 0)
                right--;
            if (left < right) {
                swap(nums[left], nums[right]);
                swaps++;
                left++;
                right--;
            }
        }
        return swaps;
    }
};