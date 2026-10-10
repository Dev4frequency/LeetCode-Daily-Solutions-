class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int sum = 0, cnt=0;
        for(auto n : nums)
        {
            sum += n;
            if(sum == 0)    cnt++;
        }
        return cnt;
    }
};