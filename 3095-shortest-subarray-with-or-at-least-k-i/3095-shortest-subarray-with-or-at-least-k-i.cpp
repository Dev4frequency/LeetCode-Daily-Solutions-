class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int res = INT_MAX,or_val = 0;
        for(int i = 0; i < nums.size(); i++){
            or_val = 0;
            for(int j = i; j < nums.size(); j++){
                or_val |= nums[j];
                if(or_val >= k ){
                    res = min(res,j-i+1);
                    break;
                }
            }
        }
        return (res <= nums.size()) ? res : -1;
    }
};