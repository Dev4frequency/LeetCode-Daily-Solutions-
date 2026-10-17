class Solution {
public:

    int dp[501];

    int dfs(vector <vector <int> > &adj, int source, vector<int>& quiet){
        int ans = source;

        if(dp[source] != -1) return dp[source];

        for(int i = 0; i < adj[source].size(); i++){
            int richer = adj[source][i];
            int rec = dfs(adj, richer, quiet);

            if(quiet[rec] < quiet[ans]) ans = rec;
        }
        return dp[source] = ans;
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        memset(dp, -1, sizeof(dp));
        int n = quiet.size();
        vector <int> ans(n, 0); 
        vector <vector <int> > adj(n);

        for(int i = 0; i < richer.size(); i++){
            int source = richer[i][1], dest = richer[i][0];
            adj[source].push_back(dest);
        }

        for(int i = 0; i < n; i++) ans[i] = i;

        for(int i = 0; i < n; i++){
            ans[i] = dfs(adj, i, quiet);
        }

        return ans;
    }
};