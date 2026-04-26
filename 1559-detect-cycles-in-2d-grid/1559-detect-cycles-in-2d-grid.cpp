class Solution {
public:
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        auto dfs = [&](auto&& self, pair<int,int> node, pair<int,int> parent) -> bool {
            auto [i,j] = node;
            vis[i][j] = true;
            char val = grid[i][j];

            for (auto [dx,dy] : dir) {
                int x = i + dx, y = j + dy;

                if (x>=0 && y>=0 && x<n && y<m && grid[x][y] == val) {
                    pair<int,int> nei = {x,y};

                    if (!vis[x][y]) {
                        if (self(self, nei, node)) return true;
                    } 
                    else if (nei != parent) {
                        return true;
                    }
                }
            }
            return false;
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    if (dfs(dfs, {i,j}, {-1,-1})) return true;
                }
            }
        }
        return false;
    }
};