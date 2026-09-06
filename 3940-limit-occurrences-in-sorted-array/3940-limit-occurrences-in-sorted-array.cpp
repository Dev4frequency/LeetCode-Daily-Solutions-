class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
       int n = nums.size(); int count = 0;
        vector<int>v; int cur = nums[0];
        for(int i = 0; i<n; i++){
            if(cur == nums[i] and count < k){
                v.push_back(nums[i]); count++;
            }
           else{
              v.push_back(nums[i]); cur = nums[i];
              count = 1;
            }
            if(count == k){
                while(i<n and nums[i]==cur){
                    i++;
                }
                i--;
                if(i+1<n)
                cur = nums[i+1];
                count = 0;
                
            }
        }
    return v;
    }
};