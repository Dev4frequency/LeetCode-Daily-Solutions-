class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                ans.push_back(nums[i]);
                nums[i]=INT_MAX;
            }
        }
         for(int i=0;i<nums.size();i++){
            if(nums[i]==pivot){
            ans.push_back(nums[i]);
            nums[i]=INT_MAX;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=INT_MAX)
            ans.push_back(nums[i]);
        }
        return ans;
        
    }
};