class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {

        int greater=nums[0];
        int leftmax=nums[0];
        int ans=0;

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<leftmax)
            {
                leftmax=greater;
                ans=i;
            }
            if(nums[i]>greater)
            {
                greater=nums[i];
            }
        }
        return ans+1;
    }
};