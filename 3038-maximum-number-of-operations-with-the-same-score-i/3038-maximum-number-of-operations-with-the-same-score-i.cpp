class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int sum=nums[0]+nums[1];
        int mx=INT_MIN;
        int ct=1;
        for(int i=2;i<nums.size();i=i+2)
        {
            
            if( i+1<nums.size() && nums[i]+nums[i+1]==sum) ct++;
            else break;

        }
       return ct;
    }
};