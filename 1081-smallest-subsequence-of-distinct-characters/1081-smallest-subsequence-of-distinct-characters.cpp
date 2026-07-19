class Solution {
public:
    string smallestSubsequence(string s) {
        string res = "";
        map<char, int> lastSeen;
        map<char, bool> taken;
        for(int i=0; i<s.size(); i++){
            lastSeen[s[i]] = i;
            taken[s[i]] = false;
        }
        for(int i=0; i<s.size(); i++){
            if(taken[s[i]] == true) continue;
            while(!res.empty() && res.back() > s[i] && lastSeen[res.back()] > i){
                taken[res.back()] = false;
                res.pop_back();
            }
            res.push_back(s[i]);
            taken[s[i]] = true;
        }
        return res;
    }
};