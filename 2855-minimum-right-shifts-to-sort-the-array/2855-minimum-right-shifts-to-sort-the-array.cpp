class Solution {
public:
    int minimumRightShifts(vector<int>& nums) 
    {
        int id=-1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[i-1])
            {
                id=i;
                break;
            }
        }
        if(id==-1) return 0;
        else
        {
            vector<int>ans;
            for(int i=id;i<nums.size();i++)
            {
                ans.push_back(nums[i]);
            }
            for(int i=0;i<id;i++)
            {
                ans.push_back(nums[i]);
            }
            sort(nums.begin(),nums.end());
            if(ans==nums) return nums.size()-id;
            else return -1;
        }
    }
};