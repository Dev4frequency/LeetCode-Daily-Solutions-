class Solution {
public:
    void dfs(int i,vector<int>& indexes,string &formed,string &s,vector<vector<int>>& adj,vector<bool>& visited){
        visited[i]=true;
        indexes.push_back(i);
        formed+=s[i];
        for(int j:adj[i]){
           if(!visited[j])
               dfs(j,indexes,formed,s,adj,visited);
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        int n=s.length();
        vector<vector<int>> adjList(n);
        vector<bool> visited(n,false);
        
        for(int i=0;i<pairs.size();i++){
            int u=pairs[i][0];
            int v=pairs[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        for(int i=0;i<s.length();i++){
            if(!visited[i]){
                string formed="";
                vector<int> indexes;
                dfs(i,indexes,formed,s,adjList,visited);
                sort(formed.begin(),formed.end());
                sort(indexes.begin(),indexes.end());
                for(int i=0;i<formed.length();i++){
                   s[indexes[i]]=formed[i];
                }
            }
        }
        return s;
    }
};