class Solution {
public:
    int beautySum(string s) {
        int sum=0;
        for(int i=0; i<s.length(); i++) {
            unordered_map<char,int> map;
            for(int j=i; j<s.length(); j++) {
                map[s[j]]++;
                int maxi=0,mini=INT_MAX;
                for(auto it: map) {
                    mini=min(mini,it.second);
                    maxi=max(maxi,it.second);
                }
                sum=sum+(maxi-mini);
            }
        }
        return sum;
    }
};