class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n=nums.size();
        int k=n;
        int low=0,high=(n+1)/2;
        while(low<n/2 && high<n){
            if(nums[low]<nums[high]){
                k-=2;
            }
            low++;
            high++;
        }
        return k;
    }
};