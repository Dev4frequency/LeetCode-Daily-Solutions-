class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,pair<int,int>> mp;

        for(int i=0; i<nums.size();i++){
            mp[nums[i]].first++;
            mp[nums[i]].second = i;
        }
        int degree=0;
        for(auto i : mp){
           degree = max(degree,i.second.first);
        }
        cout<<degree<<"";
        int shortest =INT_MAX;
        for(int i =0;i<nums.size();i++){
            if(  mp[nums[i]].first == degree ){
                    shortest = min(shortest,mp[nums[i]].second - i + 1);
                    mp[nums[i]].first = 0;
                    cout<<shortest<<" ";
            }
        }
        return shortest;
    }
};