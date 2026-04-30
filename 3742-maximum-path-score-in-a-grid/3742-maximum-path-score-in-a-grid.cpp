class Solution {

int f(int row, int col, int cost, int n , int m ,vector<vector<int>>&grid, int k, vector<vector<vector<int>>>&dp){

    if (row>=n || col>=m) return -1e9;

    int addCost= (grid[row][col]>0)? 1: 0;

    

    if (cost+addCost>k) return -1e9;

    if (row== n-1 && col== m-1) return grid[row][col];

    if (dp[row][col][cost]!=-1) return dp[row][col][cost];

    int right = grid[row][col]+f(row, col+1, cost+addCost, n, m, grid, k, dp);
    int down = grid[row][col]+f(row+1, col, cost+addCost, n, m, grid, k, dp);
    return dp[row][col][cost]= max(right, down);

    
}
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {

        int n= grid.size(); 
        int m = grid[0].size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m ,vector<int>(k+1, -1)));

        int ans= f(0, 0,0 , n, m, grid, k, dp);

        if (ans<0 ) return -1;
        return ans;

        
        
    }
};