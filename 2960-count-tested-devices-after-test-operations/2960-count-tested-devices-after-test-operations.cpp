class Solution {
public:
    int countTestedDevices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int dec = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] - dec > 0){
                ans++;
                dec++;
            }
        }
        return ans;
    }
};