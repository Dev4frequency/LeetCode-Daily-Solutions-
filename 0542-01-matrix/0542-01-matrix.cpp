#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<vector<int>> que;
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    que.push({i, j, 0});
                }
            }
        }
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!que.empty()) {
            auto cell = que.front();
            que.pop();

            int cr = cell[0];
            int cc = cell[1];
            int ct = cell[2];

            for (auto& dir : dirs) {
                int nr = cr + dir.first;
                int nc = cc + dir.second;
                int newTime = ct + 1;
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && mat[nr][nc] != 0) {
                    que.push({nr, nc, newTime});
                    mat[nr][nc] = 0;
                    res[nr][nc] = newTime;
                }
            }
        }

        return res;
    }
};