class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        int rs[1000];
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==key){
                rs[nums[i+1]-1]++;
            }
        }
        int max = INT_MIN;
        int ans =0;
        for(int i=0;i<1000;i++){
            if(max<rs[i]){
                max = rs[i];
                ans= i+1;
            }
        }
        return ans;
    }
};