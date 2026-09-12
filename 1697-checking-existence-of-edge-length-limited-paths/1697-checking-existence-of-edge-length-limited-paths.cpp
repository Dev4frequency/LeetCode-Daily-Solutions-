class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        
        sort(edgeList.begin(), edgeList.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        
        int m = queries.size();
        vector<int> idx(m);
        iota(idx.begin(), idx.end(), 0);
        
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return queries[a][2] < queries[b][2];
        });
        
        vector<bool> result(m);
        int edgeIdx = 0;
        
        for (int i : idx) {
            int u = queries[i][0];
            int v = queries[i][1];
            int limit = queries[i][2];
            
            while (edgeIdx < edgeList.size() && edgeList[edgeIdx][2] < limit) {
                unionSets(parent, edgeList[edgeIdx][0], edgeList[edgeIdx][1]);
                edgeIdx++;
            }
            
            result[i] = find(parent, u) == find(parent, v);
        }
        
        return result;
    }
    
private:
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }
    
    void unionSets(vector<int>& parent, int x, int y) {
        int rootX = find(parent, x);
        int rootY = find(parent, y);
        parent[rootY] = rootX;
    }
};