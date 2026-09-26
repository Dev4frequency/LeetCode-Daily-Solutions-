class Solution {
public:
    int subs(int i,int prev,int flag,vector<int>&nums,vector<vector<vector<int>>>&dp){
        if(i>=nums.size()) return 0;
        if(dp[i][prev][flag]!=-1) return dp[i][prev][flag];

        int pick=0,notpick=0;
        if(prev==i || (flag==1 && nums[i]>nums[prev]) || (flag==0 && nums[i]<nums[prev])) {
            pick=1+subs(i+1,i,flag==1?0:1,nums,dp);
        }
        notpick=subs(i+1,prev,flag,nums,dp);

        return dp[i][prev][flag]=max(pick,notpick);
    }
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
        return max(subs(0,0,0,nums,dp),subs(0,0,1,nums,dp));
    }
};