class Solution {
public:
    bool isSubStringBalance(int f , unordered_map<char,int>& m){
        for(auto it : m)
            if(  it.second != f )
                return false;
        return true;
    }

    int fun(int i , int n , string& str , vector<int>& dp){
        if( i==n ) return 0 ;
        if(dp[i]!=-1)  return dp[i];

        unordered_map<char,int> m ;
        int ans = INT_MAX ;
        for(int j=i ; j<n ; j++){
            m[str[j]]++;
            int f = m[str[j]] ; 
            if( isSubStringBalance(f,m) ){
                int temp = 1 + fun(j+1,n,str,dp);
                ans = min(ans,temp);
            }
        }
        return dp[i] = ans;
    }
    int minimumSubstringsInPartition(string s) {
        int n = s.size() ;
        vector<int> dp(n,-1);
        return fun(0,n,s,dp) ;
    }
};