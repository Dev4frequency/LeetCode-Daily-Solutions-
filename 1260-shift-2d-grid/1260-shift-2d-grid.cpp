class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> ans(row, vector<int>(col));
        int total = row * col;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int index = i * col + j;
                int newIndex = (index + k) % total;
                int newRow = newIndex / col;
                int newCol = newIndex % col;
                ans[newRow][newCol] = grid[i][j];
            }
        }
        return ans;
    }
};