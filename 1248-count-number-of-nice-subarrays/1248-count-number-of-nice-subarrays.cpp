class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int count = 0; 
        int ans = 0;
        int initialGap = 0;

        while (right < nums.size()) {
            if (nums[right] % 2 == 1) count++;
            
            if (count == k) {
                initialGap = 0;
                while (count == k) {
                    if (nums[left] % 2 == 1) count--;
                    initialGap++;
                    left++;
                }
            }
            
            ans += initialGap;
            right++;
        }
        
        return ans;
    }
};