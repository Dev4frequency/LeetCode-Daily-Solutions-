class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        int n=words.size();
        map<string,int>mp;
        for(int i=0;i<n;i++){
            if(words[i].size()<k)
            continue;
            string s=words[i].substr(0,k);
            if(mp.find(s)==mp.end())
            mp.insert({s,1});
            else
            mp[s]++;
        }
        int ans=0;
        for(auto i=mp.begin();i!=mp.end();i++){
            if(i->second>=2)
            ans++;
        }
        return ans;
    }
};