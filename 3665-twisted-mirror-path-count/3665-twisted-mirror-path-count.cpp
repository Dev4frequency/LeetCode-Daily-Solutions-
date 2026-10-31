class Solution {
public:
    using ll = long long;
    const int mod = 1e9 + 7;
    vector<vector<vector<int>>>dp;
    int solve(auto &grid ,int i ,int j ,int d){
        int n = grid.size();
        int m = grid[0].size();

        if(i < 0 || i >= n || j < 0 || j >= m){
            return  0;
        }

        if(i == n - 1 && j == m - 1){
            return 1;
        }

        if(dp[i][j][d] != -1){
            return dp[i][j][d];
        }

        if(grid[i][j] == 1){
            if(d){
                return dp[i][j][d] =  (solve(grid , i , j + 1 , (d + 1) % 2)) % mod;
            }else{
                return dp[i][j][d] =  (solve(grid , i + 1 , j , (d + 1) % 2)) % mod;
            }
        }
        long long  ans = 0;
        ans  = (solve(grid , i + 1 , j , 1)) % mod ;
        ans = ( ans + solve(grid , i , j + 1 , 0)) % mod;

        return dp[i][j][d] =  ans;

    }
    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        dp.assign(n + 1, vector<vector<int>>(m + 1, vector<int>(3 , -1)));

        return solve(grid, 0 ,0,0);
    }
};