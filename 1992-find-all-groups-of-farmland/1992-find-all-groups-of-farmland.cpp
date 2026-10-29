class Solution {
private:
    void dfs(vector<vector<int>>& land, int i, int j, int& bottom_i, int& bottom_j) {
        if (i < 0 || i == land.size() || j < 0 || j == land[0].size()) {
            return;
        }
        if (land[i][j] != 1) {
            return;
        }
        land[i][j] = 5;
        bottom_i = max(i, bottom_i);
        bottom_j = max(j, bottom_j);
        dfs(land, i + 1, j, bottom_i, bottom_j);
        dfs(land, i, j + 1, bottom_i, bottom_j); 
    }

public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> answer;
        int bottom_i, bottom_j;
        
        for (int i = 0; i < land.size(); i++) {
            for (int j = 0; j < land[0].size(); j++) {
                if (land[i][j] == 1) {
                    bottom_i = i;
                    bottom_j = j;
                    dfs(land, i, j, bottom_i, bottom_j);
                   answer.push_back({i, j, bottom_i, bottom_j});
                }
            }
        }
        
        return answer;
    }
};