class Solution {
public:
    int bfs(int node, auto& adj, int& n){
        vector<int> visit(n);
        visit[node] = 1;
        queue<int> q;
        q.push(node);
        int cnt = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            cnt++;
            for(auto v : adj[u]){
                if(visit[v] == 0){
                    visit[v] = 1;
                    q.push(v);
                }
            }
        }
        return cnt;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++){
            int xi = bombs[i][0];
            int yi = bombs[i][1];
            int ri = bombs[i][2];
            for(int j=0; j<n; j++){
                if(i == j) continue;
                int xj = bombs[j][0];
                int yj = bombs[j][1];
                long long distSq = (long long)(xi - xj) * (xi - xj) + (long long)(yi - yj) * (yi - yj);
                long long radiusSq = (long long)ri * ri;
                if (radiusSq >= distSq) adj[i].push_back(j);   
            }
        }
        int max_cnt = 0;
        for(int i=0; i<n; i++){
            max_cnt = max(max_cnt, bfs(i, adj, n));
        }
        return max_cnt;
    }
};