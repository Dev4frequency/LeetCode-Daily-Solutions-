class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        double ans = DBL_MAX;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n/2; i++){
            double temp = double(nums[i] + nums[n-i-1]);
            if(ans > temp){
                ans = temp;
            }
        }
        return ans/2;
    }
};