class Solution {
public:


    int longestSubsequence(vector<int>& arr, int difference) {
        

        int n = arr.size();
        map<int, int> mp;
        int ans = 1;

        for(auto x: arr)
        
        {

            if(mp.count(x-difference)){
                mp[x] = mp[x-difference]+1;
            }else{
                mp[x] = 1;
            }
            ans = max(ans, mp[x]);
        }

        return ans;
    }
};