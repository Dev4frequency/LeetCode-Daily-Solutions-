class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int>check;
        for(int i = 1; i <= k; i++){
            check.insert(i);
        }
        int ans = 0;
        for(int i = nums.size()-1; 0 <= i; i--){
            if(check.find(nums[i]) != check.end()){
                check.erase(nums[i]);
            }
            ans++;
            if(check.empty()){
                return ans;
            }
        }
        return ans;
    }
};