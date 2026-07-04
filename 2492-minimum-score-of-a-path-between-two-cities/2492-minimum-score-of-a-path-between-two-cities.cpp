class Solution {
public: 
 int ans = INT_MAX;

void dfs(int node , vector<vector<pair<int,int>>> &adj,
             vector<int> &vis)
             {
                vis[node] = 1;

                for(auto it : adj[node])
                {
                    int adjNode = it.first;
                    int wt = it.second;

                    ans = min(ans , wt);

                    if(!vis[adjNode])
                    {
                        dfs(adjNode , adj , vis);
                    }
                }
             }


    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it : roads)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        vector<int>vis(n+1 , 0);

        dfs(1 , adj, vis);

        return ans;  
        
    }
};