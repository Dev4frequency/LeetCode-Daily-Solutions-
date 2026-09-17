class Solution {
public:
    string findValidPair(string s) {
        string ans = "";
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++){
            char c = s[i];
            mp[c]++;
        }
        for(int i=0;i<s.length();i++){
            if(s[i] != s[i+1] && mp[s[i]] == s[i] - '0' && mp[s[i+1]] == s[i+1] - '0'){
                ans.push_back(s[i]);
                ans.push_back(s[i+1]);
                // i++;
                break;
            }
        }
        return ans;
        
    }
};