class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        if(nums.size() == 1){
            return {0,1};
        }
        vector<int>ans;
        ans.push_back(0);
        sort(nums.begin(),nums.end());
        int n =  nums.size();
        for(int i = 0; i < n-1; i++){
            if(nums[i] == nums[i+1]){
                ans[0]++;
                i++;
            }
        }
        ans.push_back(n - (ans[0]*2));
        return ans;
    }
};