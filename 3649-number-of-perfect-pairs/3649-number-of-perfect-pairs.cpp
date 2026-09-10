class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                nums[i]*=(-1);
            }
        }
        sort(nums.begin(),nums.end());
        long long ans = 0;
        int start = 0;
        int end = n-1;
        for(int i = 0;i<n;i++){
           auto lowerBound = lower_bound(nums.begin(),nums.end(),2*nums[i]+1);
           int smaller = lowerBound - (nums.begin()+i);
           if(smaller > 0){
            smaller -= 1;
           }
           ans += smaller;
        }
        return ans;
    }
};