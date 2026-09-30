class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0, minsum = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            minsum = min(minsum, sum);
        }

        if(minsum < 0)
            return 1 - minsum;

        return 1;
    }
};