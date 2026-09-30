class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        int ans = 0;
        
        for (auto& ind : indices) {
            int r = ind[0], c = ind[1];
            
            for (int j = 0; j < n; j++) {
                matrix[r][j]++;
            }
            
            for (int i = 0; i < m; i++) {
                matrix[i][c]++;
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] % 2 == 1) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};