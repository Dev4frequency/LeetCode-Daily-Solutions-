class Solution {
    void solve(int node, int c, vector<int>& vis, vector<vector<int>> &graph){
        vis[node] = c;
        for(auto neigh : graph[node]){
            if (vis[neigh] == -1) { 
                solve(neigh, c, vis, graph);
            }
        }
    }
public:
    bool equationsPossible(vector<string>& equations) {
        vector<vector<int>> graph(26);
        for(auto &it : equations){
            if(it[1] == '='){
                int first = it[0] - 'a';
                int second = it[3] - 'a';
                graph[first].push_back(second);
                graph[second].push_back(first);
            }
        }
        vector<int> vis(26, -1);
        for(int i = 0; i < 26; i++){
            if (vis[i] == -1){
                solve(i, i, vis, graph);
            }
        }
        for(auto &it : equations){
            if(it[1] == '!'){
                int first = it[0] - 'a';
                int second = it[3] - 'a';
                if(vis[first] == vis[second]) return false;
            }
        }
        return true;
    }
};