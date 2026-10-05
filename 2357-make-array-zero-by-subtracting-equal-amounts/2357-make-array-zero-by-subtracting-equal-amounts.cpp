class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt =0;
        set<int>s(nums.begin(), nums.end());
       
        for(auto it: s){
            if(it != 0 ){
                cnt++;
            }
        }
        return cnt;
    }
};