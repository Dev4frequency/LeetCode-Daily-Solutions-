class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1) return 0;
        sort(nums.begin(),nums.end());
        int ans=nums[n-1]-nums[0];
        for(int i=0;i<n-1;i++){
            int mi=min(nums[0]+k,nums[i+1]-k);
            int ma=max(nums[i]+k,nums[n-1]-k);
            ans=min(ans,ma-mi);
        }
        return ans;
    }
};