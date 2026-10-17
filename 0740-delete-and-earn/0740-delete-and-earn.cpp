class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {

        int maxi=0;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
        }

        vector<int>temp(maxi+1,0);
        for(int num:nums){
            temp[num]+=num;
        }

        int prev=temp[0];
        int prev2=0;
        for(int i=1;i<=maxi;i++){
            int cur=max(prev,prev2+temp[i]);
            prev2=prev;
            prev=cur;
        }

        return prev;
    }
};