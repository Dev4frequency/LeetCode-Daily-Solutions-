class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int count = 0;
        for(auto &ele : nums){
            if( !(ele & 1) ){
                count++;
            }
            if(count > 1){
                return true;
            }
        }
        return false;
    }
};