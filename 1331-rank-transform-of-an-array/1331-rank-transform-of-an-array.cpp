class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        set<int>st(arr.begin(), arr.end());
        unordered_map<int, int>mp;

        int cnt = 1;
        for(auto it:st){
            mp[it] = cnt++;
        }

        vector<int>res;
        for(auto it:arr){
               res.push_back(mp[it]);
        }

        return res;

    }
};