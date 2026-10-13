class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums;
        
        vector<int> lMax(n), rMax(n), v;

        lMax[0] = nums[0];
        for(int i = 1; i < n; i++) {
            lMax[i] = max(lMax[i-1], nums[i-1]);
        }

        rMax[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--) {
            rMax[i] = max(rMax[i+1], nums[i+1]);
        }

        for(int i = 0; i < n; i++) {
            if(i == 0 || i == n-1 || nums[i] > lMax[i] || nums[i] > rMax[i]) {
                v.push_back(nums[i]);
            }
        }
        
        return v;
    }
};