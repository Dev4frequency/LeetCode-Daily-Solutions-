class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)return 0;
        int l =0;
        int count= 0;
        int product = 1;
        for(int j= 0;j<nums.size();j++){
            product*=nums[j];
            while(product>=k){
                product/=nums[l];
                l++;
            }
            if(product<=k){
                count+=(j-l+1);
            }
        }
        return count;
    }
};