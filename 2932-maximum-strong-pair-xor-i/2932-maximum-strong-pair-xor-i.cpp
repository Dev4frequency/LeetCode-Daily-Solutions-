class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            for(int j = i+1; j < nums.size(); j++){
                int a = nums[i];
                int b = nums[j];
                int sub = 0;
                (a < b) ? sub = (b - a) : sub = (a - b);
                if( sub <= min(a,b)){
                    res = max(res,a xor b);
                }
            }
        }
        return res;
    }
};