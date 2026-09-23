class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        map<string, int>mp;
        unordered_set<string>s;
        for(int i=0;i<responses.size();i++){
            for(int j=0;j<responses[i].size();j++){
                if(s.find(responses[i][j]) ==s.end()){
                    mp[responses[i][j]]++;
                    s.insert(responses[i][j]);
                }                    
            }
            s.clear();
        }
        int maxfreq=0;
        string ans="";
        for(auto x : mp){
            if(maxfreq < x.second){
                maxfreq=x.second;
                ans=x.first;
            }
        }
        return ans;
    }
};