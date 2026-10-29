class Solution {
    const int INF = 1e6;
    
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = (int)patience.size();
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> dist(n, INF);
        auto cmp = [](auto& a, auto& b) {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq;
        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [u, w] = pq.top();
            pq.pop();
            if (dist[u] < w) {
                continue;
            }

            for (int v : graph[u]) {
                if (dist[u] + 1 < dist[v]) {
                    dist[v] = dist[u] + 1;
                    pq.push({v, dist[v]});
                }
            }
        }

        int ans = 0;
        auto calcTime = [&](int idx) -> int {
            return (dist[idx] * 2 - 1) / patience[idx] * patience[idx] + dist[idx] * 2 + 1;
        };
        for (int i = 1; i < n; ++i) {
            ans = max(ans, calcTime(i));
        }
        return ans;
    }
};