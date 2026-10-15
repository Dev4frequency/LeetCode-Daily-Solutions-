class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i <= 31; i++){
            int x = 0;
            for(int j = 0; j < n; j++){
                if(nums[j] & (1<<i))x++;
            }
            ans += (x*(n-x));
        }
        return ans;
    }
};