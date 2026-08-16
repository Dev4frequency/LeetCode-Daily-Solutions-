class Solution {
public:
    #define pp pair<int,int>
    #define F first
    #define S second
    vector<int> prime;     
    void comp(){
        prime.resize(100010,1);
        for(int i=2;i*i<=100000;i++){
            if(!prime[i]) continue;
            for(int j=i*i;j<=100000;j +=i){
                prime[j] = 0;
            }
        }
        prime[1] = 0;
    }
    vector<vector<int>> g;
    vector<int> vis,arr,vis1;
    int n;
    int dfs(int node){
        int ct = 1;
        vis[node] = 1;
        for(auto x: g[node]){
            if(!vis[x]){
                ct +=dfs(x);
            }
        }
        return ct;
    }
    void setting(int node,int val){
        vis1[node] = 1;
        arr[node] = val;
        for(auto x: g[node]){
            if(!vis1[x]){
                setting(x,val);
            }
        }
    }
    long long countPaths(int n, vector<vector<int>>& edges) {
        this->n = n;
        comp();
        g.resize(n+1);
        vis.resize(n+1,0);
        arr.resize(n+1,0);
        vis1.resize(n+1,0);
        vector<vector<int>> grid(n+1);
        for(auto x: edges){
            if(prime[x[0]] || prime[x[1]]){

            }else{
                g[x[0]].push_back(x[1]);
                g[x[1]].push_back(x[0]);
            }
            grid[x[1]].push_back(x[0]);
            grid[x[0]].push_back(x[1]);
        }
        for(int i=1;i<=n;i++){
            if(!vis[i] && !prime[i]){
                int ct = dfs(i);
                setting(i,ct);
            }
        }
        long long ans = 0;
        for(int i=1;i<=n;i++){
            if(prime[i]){
                vector<int> temp;
                for(auto x: grid[i]){
                    if(!prime[x]){
                        temp.push_back(arr[x]);
                        ans +=arr[x];
                    }
                }
                sort(temp.begin(),temp.end());
                vector<int> pre = temp;
                for(int j=1;j<pre.size();j++){
                    pre[j] +=pre[j-1];
                }
                for(int j=0;j<temp.size();j++){
                    ans +=((pre[temp.size()-1]-pre[j])*temp[j]);
                }
            }
        }
        return ans;
    }
};