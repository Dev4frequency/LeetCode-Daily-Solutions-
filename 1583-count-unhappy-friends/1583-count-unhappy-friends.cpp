class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<vector<int>> rank(n, vector<int>(n, 0));
        vector<int> partner(n, -1);
        for (auto& p : pairs) {
            partner[p[0]] = p[1];
            partner[p[1]] = p[0];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                rank[i][preferences[i][j]] = j;
            }
        }
        int unhappyCount = 0;
        for (int x = 0; x < n; x++) {
            int y = partner[x];
            for (int u = 0; u < n; u++) {
                if (u != x && u != y) {
                    int v = partner[u];
                    if (rank[x][u] < rank[x][y] && rank[u][x] < rank[u][v]) {
                        unhappyCount++;
                        break;
                    }
                }
            }
        }
        return unhappyCount;
    }
};