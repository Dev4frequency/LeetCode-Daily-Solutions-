class Solution {
public:
    unordered_map<int,vector<int>> graph;
    void genGraph(vector<vector<int>>& edges){
        for(auto edge:edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
    }
    vector<int> dfs(int node, vector<int>& res, unordered_map<int,bool>& visited,string& labels){
        vector<int> labelMap(26,0);
        if(visited[node]) return labelMap;
        visited[node] = true;
        for(auto neighbor:graph[node]){
            vector<int> labelMapped = dfs(neighbor,res,visited,labels);
            for(int it=0; it<26; it++) labelMap[it] += labelMapped[it];
        }
        labelMap[labels[node]-'a']++;
        res[node] = labelMap[labels[node]-'a'];
        return labelMap;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> res(n,0);
        unordered_map<int,bool> visited;
        genGraph(edges);
        dfs(0,res,visited,labels);
        return res;        
    }
};