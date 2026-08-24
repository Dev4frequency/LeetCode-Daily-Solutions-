class Solution {
    long long ans;
private:
    int factorize(int val) {
        map<int,int> mpp;
        while(val % 2 == 0) {
            mpp[2]++;
            val /= 2;
        }
        for(int i = 3; i * i <= val; i += 2) {
            while(val % i == 0) {
                mpp[i]++;
                val /= i;
            }
        }
        if(val > 1) mpp[val]++;
        int mul = 1;
        for(auto [x,y]:mpp) {
            if(y&1) mul *= x;
        }
        return mul;
    }
    void dfs(int node, int par, int cnt, map<int,int> &temp, vector<int> &nums, vector<vector<int>> &adj) {
        int x = sqrtl(nums[node]);
        int y = factorize(nums[node]);
        if(x * x == nums[node]) cnt++;
        else temp[y]++;
        
        for(int ngh:adj[node]) {
            if(ngh == par) continue;
            dfs(ngh, node, cnt, temp, nums, adj);
        }

        if(x * x == nums[node]) {
            cnt--;
            ans += cnt;
        }
        else {
            temp[y]--;
            ans += temp[y];
        }

    }
public:
    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        ans = 0; int cnt = 0;
        map<int,int> temp;
        
        int x = sqrtl(nums[0]);
        if(x * x == nums[0]) cnt++;
        else temp[factorize(nums[0])]++;
    
        for(int ngh:adj[0]) {
            dfs(ngh, 0, cnt, temp, nums, adj);
        }
        return ans;
    }
};