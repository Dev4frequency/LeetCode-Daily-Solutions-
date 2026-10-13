class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int c=0;
        for(int i=0;i<nums.size()-1;i++){
            auto sum=0;
            for(int j=i+1;j<nums.size();j++){
                sum+=nums[j];
                
            }
            auto avg = sum / (nums.size() - i - 1);
            if(avg<nums[i])
            c++;
        }
        return c;
    }
};