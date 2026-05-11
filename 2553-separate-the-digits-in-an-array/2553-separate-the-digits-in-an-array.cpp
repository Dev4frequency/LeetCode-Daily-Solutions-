class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
         vector<int> v;
        short int i;
        for(i=nums.size()-1;i>=0;i--)
        {
            int temp=nums[i];
             while(temp)
            {
                 v.push_back(temp%10);
                temp=temp/10;
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }
};