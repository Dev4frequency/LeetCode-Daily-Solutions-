class Solution {
public:
int findGroup(vector<int>& group, int i) {
        if (group[i] == i) 
            return i;
        else
         return group[i] = findGroup(group, group[i]);
    }
    void unionGroup(vector<int>& group, vector<int>& edgeCount, vector<int>& nodeCount, int i, int j) {
        int groupI = findGroup(group, i);
        int groupJ = findGroup(group, j);
        if (groupI != groupJ) {
            group[groupJ] = groupI;
            edgeCount[groupI] += edgeCount[groupJ];
            nodeCount[groupI] += nodeCount[groupJ];
        }
         edgeCount[groupI]++;
    }
     int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> group(n), edgeCount(n, 0), nodeCount(n, 1);
        for (int i = 0; i < n; i++) 
            group[i] = i;
             for (vector<int>& edge : edges) 
            unionGroup(group, edgeCount, nodeCount, edge[0], edge[1]);
        for (int i = 0; i < n; i++) 
            findGroup(group, i);
            sort(group.begin(), group.end());
        auto lastUnique = unique(group.begin(), group.end());
        group.erase(lastUnique, group.end());

        int completeComponentsCount = 0;
         for (int el : group) {
             if (nodeCount[el] * (nodeCount[el] - 1) / 2 == edgeCount[el]) 
                completeComponentsCount++;
        }
        return completeComponentsCount;
    }
};