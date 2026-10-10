class Solution {
public:
    int min(int a){
        int m = INT_MAX;
        if(a < m){
            m = a;
        }
        return m;
    }
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(min(nums[i]) < k){
                cnt++;
            }
        }
        return cnt;
    }
};