class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int res = 0;
        vector<int> bit(32,0);
        for( auto &ele : nums){
            int pos = 0;
            while ( ele > 0){
                if(ele & 1){
                    bit[31 - pos] += 1;
                }
                ele >>= 1;
                pos++;
            }
        }
        for( auto &ele : bit){
            if( ele >= k){
                res<<=1;
                res|=1;
            } else {
                res<<=1;
            }
        }
        return res;
    }
};