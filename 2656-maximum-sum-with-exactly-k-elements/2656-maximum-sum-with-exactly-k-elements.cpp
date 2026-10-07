class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end(),greater<int>());
        int x=nums[0];
        int sum=0;
        while(k>0)
        {
            sum=sum+nums[0];
            nums[0]=nums[0]+1;
            k--;
        }
        return sum;
    }
};