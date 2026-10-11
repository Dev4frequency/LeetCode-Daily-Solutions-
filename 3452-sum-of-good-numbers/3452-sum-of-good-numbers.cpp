class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int sum = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            bool left_valid = (i - k >= 0);
            bool right_valid = (i + k < n);
            
            if (left_valid && right_valid) {
                if (nums[i] > nums[i - k] && nums[i] > nums[i + k]) {
                    sum += nums[i];
                }
            } 
            else if (left_valid) {
                if (nums[i] > nums[i - k]) {
                    sum += nums[i];
                }
            } 
            else if (right_valid) {
                if (nums[i] > nums[i + k]) {
                    sum += nums[i];
                }
            }
        }
        
        return sum;
    }
};
