class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m/2; ++i){
            for(int j = 0; j < n/2; ++j){
                int p = grid[i][j] + grid[i][n-j-1] + grid[m-i-1][j] + grid[m-i-1][n-j-1];
                res += min(p,4-p);
            }
        }
        if (m%2 == 1 && n%2 == 1){
            res += grid[m/2][n/2];
        }
        int count_1 = 0;
        int flip = 0; 
        if (m%2 == 1){
            for (int j = 0; j < n/2; ++j){
                flip += grid[m/2][j] ^ grid[m/2][n-j-1];
                count_1 += grid[m/2][j] & grid[m/2][n-j-1];
            }
        }
        if (n%2 == 1){
            for (int i = 0; i < m/2; ++i){
                flip += grid[i][n/2] ^ grid[m-i-1][n/2];
                count_1 += grid[i][n/2] & grid[m-i-1][n/2];
            }
        }
        return (flip == 0 && count_1 % 2 == 0 || flip != 0)?res+flip:res+2;
    }
};