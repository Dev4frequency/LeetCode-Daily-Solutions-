class Solution {
public:
    
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n = word.length();
        int ans = INT_MAX;
        unordered_map<string,int>mp;
        for(int i=0;i<n;i+=k){
            string sub = word.substr(i, k);
            mp[sub]++;
        }
        int maxFreq = 0,operations=0;
        for (auto& entry : mp) {
            maxFreq = max(maxFreq, entry.second);
        }
        return n/k - maxFreq;
    }
};