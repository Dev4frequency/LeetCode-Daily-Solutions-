class Solution {
public:
    int help(int i,int j,string &s)
    {
        while(i<=j)
        {
            if(s[i]!=s[j]) return 0;
            i++;
            j--;
        }
        return 1;
    }
    int longestPalindrome(string s, string t) 
    {
        int n=s.size();
        vector<int>dp1(n+1,0);
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                int num=help(i,j,s);
                if(num==1) dp1[i+1]=max(dp1[i+1],j-i+1);
            }
        }

        int m=t.size();
        vector<int>dp2(m+2,0);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<=i;j++)
            {
                int num=help(j,i,t);
                if(num==1) dp2[i+1]=max(dp2[i+1],i-j+1);
            }
        }
        vector<vector<int>>dp(n+2,vector<int>(m+2,0));
        
        for(int i = 0; i < n; i++) dp[i][0] = dp1[i+1];
        for(int j = 1; j <= m; j++) dp[n][j] = dp2[j];
        int ans = 0;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 1; j <= m; j++) {
                dp[i][j] = max(dp1[i+1], dp2[j]);
                if (s[i] == t[j - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 2);
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};