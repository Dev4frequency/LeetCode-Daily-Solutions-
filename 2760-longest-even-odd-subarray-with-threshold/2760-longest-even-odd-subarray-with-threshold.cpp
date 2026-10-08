class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();
        int ans = 0;
        
        for (int l = 0; l < n; l++) {
            if (nums[l] % 2 != 0 || nums[l] > threshold) continue; 
            
            int r = l;
            while (r + 1 < n && nums[r] <= threshold && nums[r + 1] <= threshold 
                   && nums[r] % 2 != nums[r + 1] % 2) {
                r++;
            }
            ans = max(ans, r - l + 1);
        }
        
        return ans;
    }
};