class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(nums.size() == 1 && k%2==1) return -1;
        else if(k == 1) return nums[k];
        if(k==0) return nums[0];
        int MaxVal = *max_element(nums.begin(),nums.end());
        if(nums.size() < k) return MaxVal;

        if(nums.size() >= k) {
            int Max = *max_element(nums.begin(), nums.begin()+ k -1);
            if(Max<nums[k]) return nums[k];
            return Max;
        }
        return -1;
}
};