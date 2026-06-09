class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int min=*min_element(nums.begin(),nums.end());
        int max=*max_element(nums.begin(),nums.end());

        long long diff=max-min;

        return k*diff;
    }
};