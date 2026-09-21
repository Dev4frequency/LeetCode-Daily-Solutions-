class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        int n=hours.size();
        long long result=0;
        
        unordered_map<int,int>mp;

        for(auto it:hours)
        {
            mp[it%24]++;
        }
        
        for(auto it:mp)
        {
            if(it.first>0 && it.first<12)
            {
                int rem=24-it.first;
                if(mp.find(rem)!=mp.end())
                {
                    result+=(long long)it.second*mp[rem];
                }
            }
        }
        
        if(mp[0]>1)
        {
            result+=(long long)mp[0]*(mp[0]-1)/2;
        }
        
        if(mp[12]>1)
        {
            result+=(long long)mp[12]*(mp[12]-1)/2;
        }
        
        return result;
    }
};