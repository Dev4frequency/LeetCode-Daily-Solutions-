class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int p = parent.size();
        vector<vector<int>> adj(p); 
        vector<int> answer(p, 1);   
        for (int i = 1; i < p; ++i) adj[parent[i]].push_back(i);
        vector<int> newParent = parent; 
        unordered_map<char, vector<int>> lastSeen; 
        function<void(int)> reassignParents = [&](int node) {
            char c = s[node];
            if (!lastSeen[c].empty()) newParent[node] = lastSeen[c].back();
            lastSeen[c].push_back(node);
            for (int child : adj[node]) reassignParents(child);
            lastSeen[c].pop_back();
        };
        reassignParents(0); 
        vector<vector<int>> newAdj(p); 
        for (int i = 1; i < p; ++i) newAdj[newParent[i]].push_back(i);
        function<int(int)> computeSubtreeSizes = [&](int node) {
            int size = 1; 
            for (int child : newAdj[node]) size += computeSubtreeSizes(child);
            answer[node] = size;
            return size;
        };
        computeSubtreeSizes(0); 
        return answer;
    }
};