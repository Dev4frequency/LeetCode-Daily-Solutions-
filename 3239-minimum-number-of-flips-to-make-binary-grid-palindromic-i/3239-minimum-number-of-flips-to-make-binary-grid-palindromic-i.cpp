class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int rowChanges = 0;
        int colChanges = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    if(grid[m - i - 1][j] == 0){
                        rowChanges++;
                    }
                    if(grid[i][n - j - 1] == 0){
                        colChanges++;
                    }
                }
            }
        }
        return min(rowChanges , colChanges);
    }
};