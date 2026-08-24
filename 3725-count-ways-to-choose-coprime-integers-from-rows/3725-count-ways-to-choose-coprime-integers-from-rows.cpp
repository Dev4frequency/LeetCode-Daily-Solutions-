class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    int MOD = 1e9+7;

    long long solve(int index,vector<vector<int>>& mat,int gcdVal,vector<vector<long long>>& dp){
        if(index == mat.size()){
            return gcdVal == 1 ? 1 : 0;
        }
        if(dp[index][gcdVal] != -1){
            return dp[index][gcdVal];
        }
        long long count = 0;
        for(int i = 0;i<mat[index].size();i++){
            long long newGcd = gcdVal == 0 ? mat[index][i] : gcd(gcdVal,mat[index][i]);
            long long val = solve(index+1,mat,newGcd,dp);
            count = (count+val)%MOD;
        }
        dp[index][gcdVal] = count;
        return dp[index][gcdVal];
    }

    int countCoprime(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<long long>> dp(n+1,vector<long long>(151,-1));
        long long ans = solve(0,mat,0,dp);
        return ans;
    }
};