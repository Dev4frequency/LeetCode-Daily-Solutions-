class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
    int area = 0;
    for (int i = 0; i < grid.size(); i++ ) {
        int row = 0;
        int col = 0;
        for (int j = 0; j < grid[0].size(); j++) {
            area += grid[i][j] ? 1 : 0;
            row = max(row, grid[i][j]);
            col = max(col, grid[j][i]);
        }
        area += row + col;
    }

    return area;
}
};