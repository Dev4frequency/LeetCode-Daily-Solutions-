class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<int>ans;
        int n = nums.size(), i = n-1, num = 0;
        while( i >= 0 && num < k){
            if(i < n-1 && nums[i] == nums[i+1]){
                i--;
            } else {
                ans.push_back(nums[i]);
                num++;
                i--;
            }
        }
        return ans;
    }
};