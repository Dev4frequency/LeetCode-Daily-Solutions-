class Solution {
public:
    string lastNonEmptyString(string s) {
        int n = s.length();
        unordered_map<char,set<int>>freq;
        for(int i=0;i<n;i++){
            char ch = s[i];
            freq[ch].insert(i);
        }
        int count = freq.size();

        while(n>0){
            n = n - count;
            count =0;
            if(n>0){
                for(auto &it: freq){
                   auto &indxs = it.second;
                   auto it1 = indxs.begin();
                   if(it1 != indxs.end()){
                       indxs.erase(it1);
                   }
                   if(indxs.size()>0){
                      count++;
                   }
                }
            }
            else{
                break;
            }
        }
        string ans = "";
        set<pair<int,char>>idxs;
        for(auto it:freq){
            char ch = it.first;
            auto indxs = it.second;
            if(indxs.size()==0) continue; 
            for (auto it = indxs.begin(); it != indxs.end(); ++it) {
                    idxs.insert({*it,ch});
              }
        }
        for (auto it = idxs.begin(); it != idxs.end(); ++it) {
                   auto pairs = *it;

                    ans.push_back(pairs.second);
              }
        return ans;


    }
};