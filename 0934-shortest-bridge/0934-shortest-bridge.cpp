class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        queue<pair<int, int>> q;

        function<void(int, int)> dfs = [&](int i, int j) {
            visited[i][j] = 1;
            q.push({i, j});
            for (int d = 0; d < 4; ++d) {
                int x = i + ((d == 0) - (d == 1));
                int y = j + ((d == 2) - (d == 3));
                if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1 && !visited[x][y]) 
                    dfs(x, y);
            }
        };

        // Find the first island
        bool found = false;
        for (int i = 0; i < n && !found; ++i) {
            for (int j = 0; j < n && !found; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    dfs(i, j); 
                    found = true;
                }
            }
        }
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [x, y] = q.front(); q.pop();
                for (int d = 0; d < 4; ++d) {
                    int nx = x + ((d == 0) - (d == 1));
                    int ny = y + ((d == 2) - (d == 3));
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                        if (grid[nx][ny] == 1 && visited[nx][ny] == 0) return ans;
                        if (!visited[nx][ny]) {
                            visited[nx][ny] = 1;
                            q.push({nx, ny});
                        }
                    }
                }
            }
            ++ans;
        }
        
        return ans;
    }
};