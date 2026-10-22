class Solution {
public:
    int divSum(vector<int>&nums, int mid){
        int sum=0;
        for(int num:nums){
            sum+=(num+mid-1)/mid;
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi=0;
        for(int num:nums){
            maxi=max(maxi,num);
        }
        int low=1,high=maxi;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            int val=divSum(nums,mid);
            if(val<=threshold){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};