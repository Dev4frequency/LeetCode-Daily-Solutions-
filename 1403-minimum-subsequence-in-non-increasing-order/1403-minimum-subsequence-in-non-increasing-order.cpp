class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int tot=accumulate(nums.begin(),nums.end(),0);
        int sum=0;
        vector<int>res;
        for(int num:nums){
            sum+=num;
            res.push_back(num);
            if(sum>tot-sum) break;
        }
        return res;
    }
};