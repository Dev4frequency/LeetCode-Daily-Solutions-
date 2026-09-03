class Solution {
public:
bool compare(string& s1,string& s2){
int first=0;
int second=0;
if(s1.size()!=s2.size()+1) return false;
while(first<s1.size()){
    if(second<s2.size()&&s1[first]==s2[second]){
        first++;
        second++;
    }
    else{
        first++;
    }
}
    if(first==s1.size()&&second==s2.size()) return true;
    else
return false;

}
static bool comp(string& s1,string& s2){
    return s1.size() < s2.size();
}
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(),comp);
        int n=words.size();
        vector<int> dp(n,1);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(compare(words[i],words[prev])&&dp[i]<dp[prev]+1){
dp[i]=dp[prev]+1;
                }
            }
             maxi = max(maxi, dp[i]);
    }
    return maxi;
        }
    
};