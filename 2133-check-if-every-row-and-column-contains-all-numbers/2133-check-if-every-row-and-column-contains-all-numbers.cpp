class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; i++) {
            vector<bool> row(n+1, false), col(n+1, false);
            for (int j = 0; j < n; j++) {
                if (row[matrix[i][j]]) return false;
                row[matrix[i][j]] = true;

                if (col[matrix[j][i]]) return false;
                col[matrix[j][i]] = true;
            }
        }
        return true;
    }
};