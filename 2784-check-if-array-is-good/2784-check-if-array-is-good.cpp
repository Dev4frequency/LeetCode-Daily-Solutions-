class Solution {
public:
    bool isGood(vector<int>& nums) {
        if (nums.size() < 2) return false;
        
        sort(nums.begin(), nums.end());
        int n = nums.size() - 1; 
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) return false;
        }
         return nums.back() == n;
    }
};
