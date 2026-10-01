class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int > mp;
        for(int i = 0 ; i< nums.size();i++){
            mp[nums[i]] = i;
        }
        for(int i  =0 ; i < nums.size() ; i++){
            int new_val = target - nums[i];
            if(mp.find(new_val) != mp.end() && mp[new_val] != i){
                return {i , mp[new_val]};
            }
        }
        return {};
    }
};