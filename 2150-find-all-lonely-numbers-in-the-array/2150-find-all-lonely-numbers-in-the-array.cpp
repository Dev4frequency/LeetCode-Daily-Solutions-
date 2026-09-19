class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(auto a: nums) mp[a]++;
        for(auto x:mp){
            if(x.second==1 && !mp.count(x.first+1) && !mp.count(x.first-1))
            ans.emplace_back(x.first);
        }
        return ans;
    }
};