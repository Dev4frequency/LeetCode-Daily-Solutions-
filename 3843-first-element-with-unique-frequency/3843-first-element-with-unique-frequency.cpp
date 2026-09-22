class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto& n:nums){
            mp[n]++;
        }
        
        unordered_map<int,int>m;
        for(auto&it:mp){
            m[it.second]++;
        }
        for(auto&n:nums){
            if(m[mp[n]]==1)
            return n;
        }return -1;
    }
};