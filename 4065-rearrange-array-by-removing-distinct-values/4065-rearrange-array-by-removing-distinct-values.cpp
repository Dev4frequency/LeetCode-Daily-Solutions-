class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>result;
        int c =0;
        while(c<n)
        {
         int i =0;
            while(i<n){
                if(nums[i] != INT_MAX){
                    result.push_back(nums[i]);
                    int v = nums[i];
                    nums[i]=INT_MAX;
                    c++;
                    i++;
                while(i<n && nums[i] == v){
                    i++;
                }
            }
            else
            {
                i++;
            }
        }
            
        }
        return result;
        
    }
};