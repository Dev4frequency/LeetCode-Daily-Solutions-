class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int ,int> mp;

        for(auto n: nums){
            mp[n]++;
        }

        for(auto n: nums){
            if(n % 2 == 0 && mp[n] == 1){
                return n;
            }
        }
        return -1;
    }
};