class Solution {
public:
    int arraySign(vector<int>& nums) {
        int z=0,n=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
            n++;
            else if(nums[i]==0)
            z=1;
        }
        if(z==1) return 0;
        if(n%2!=0) return -1;
        return 1;
    }
};