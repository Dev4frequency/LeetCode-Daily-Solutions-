class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (const auto& e : edges)
            adj[e[0]].push_back({e[1], e[2]});

        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));
        dist[0][1] = 0;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>pq;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [cost, u, cnt] = pq.top(); 
            pq.pop();

            if (cost > dist[u][cnt])
                continue;

            if (u == n - 1)
                return cost;
            
            for(auto &[v, w] : adj[u]) {
                int newCnt = (labels[u] == labels[v]) ? cnt + 1 : 1;

                if(newCnt > k)
                    continue;
                
                if(cost + w < dist[v][newCnt]) {
                    dist[v][newCnt] = cost + w;
                    pq.push({cost + w, v, newCnt});
                }
            }
        }

        return -1;
    }
};