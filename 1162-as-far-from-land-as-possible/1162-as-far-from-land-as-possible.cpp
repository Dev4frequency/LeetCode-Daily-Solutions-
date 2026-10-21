class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dis(n, vector<int>(n, 1e9));
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.push({{i, j}, 0});
                    dis[i][j] = 0;
                }
            }
        }

        int ans = 0;
        while (!q.empty()) {
            auto tp = q.front();
            q.pop();
            int curr_row = tp.first.first;
            int curr_col = tp.first.second;
            int curr_dist = tp.second;
            ans = max(ans, curr_dist);

            for (int k = 0; k < 4; ++k) {
                int new_row = curr_row + dx[k];
                int new_col = curr_col + dy[k];

                if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < n &&
                    dis[new_row][new_col] > curr_dist + 1 && grid[new_row][new_col] == 0) {
                    dis[new_row][new_col] = curr_dist + 1;
                    q.push({{new_row, new_col}, curr_dist + 1});
                }
            }
        }

        return ans == 0 ? -1 : ans;
    }
};