class Solution {
public:
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};
    
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        
        int startDamage = grid[0][0];
        if (startDamage >= health) return false;
        
        pq.push({startDamage, 0, 0});
        dist[0][0] = startDamage;
        
        while (!pq.empty()) {
            auto [damage, r, c] = pq.top(); pq.pop();
            
            if (r == m - 1 && c == n - 1) return damage < health;
            if (damage > dist[r][c]) continue;
            
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nc >= 0 && nr < m && nc < n) {
                    int newDamage = damage + grid[nr][nc];
                    if (newDamage < dist[nr][nc] && newDamage < health) {
                        dist[nr][nc] = newDamage;
                        pq.push({newDamage, nr, nc});
                    }
                }
            }
        }
        return false;
    }
};