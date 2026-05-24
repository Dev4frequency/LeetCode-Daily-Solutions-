class Solution {
public:
    int dfs(int node, vector<vector<int>>& adj, vector<int>& dp)
    {
        if(dp[node] != -1)
            return dp[node];

        int maxi = 1;

        for(auto nextNode : adj[node])
        {
            maxi = max(maxi, 1 + dfs(nextNode, adj, dp));
        }

        return dp[node] = maxi;
    }

    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++)
        {
            for(int j = i - 1; j >= max(0, i - d); j--)
            {
                if(arr[j] >= arr[i])
                    break;

                adj[i].push_back(j);
            }
            for(int j = i + 1; j <= min(n - 1, i + d); j++)
            {
                if(arr[j] >= arr[i])
                    break;

                adj[i].push_back(j);
            }
        }
        vector<int> dp(n, -1);

        int maxi = 1;

        for(int i = 0; i < n; i++)
        {
            maxi = max(maxi, dfs(i, adj, dp));
        }

        return maxi;
    }
};