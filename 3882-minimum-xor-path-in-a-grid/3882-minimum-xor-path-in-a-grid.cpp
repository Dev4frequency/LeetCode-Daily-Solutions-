class Solution {
private:
    int ans;
    vector<vector<vector<bool>>> visited;

    void dfs(
        vector<vector<int>>& grid,
        int row,
        int col,
        int m,
        int n,
        int x
    ) {
        x ^= grid[row][col];

        if (visited[row][col][x]) {
            return;
        }

        visited[row][col][x] = true;

        if (row == m - 1 && col == n - 1) {
            ans = min(ans, x);
            return;
        }

        if (row + 1 < m) {
            dfs(grid, row + 1, col, m, n, x);
        }

        if (col + 1 < n) {
            dfs(grid, row, col + 1, m, n, x);
        }
    }

public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        ans = INT_MAX;
        visited.assign(
            m,
            vector<vector<bool>>(n, vector<bool>(1024, false))
        );

        dfs(grid, 0, 0, m, n, 0);

        return ans;
    }
};