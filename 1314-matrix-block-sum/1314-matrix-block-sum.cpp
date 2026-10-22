class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m= mat.size(), n = mat[0].size();
        vector<vector<int> > psum(m, vector<int>(n));
        vector<vector<int> > result(m, vector<int>(n));
        psum[0][0] = mat[0][0]; 
        for(int i=1; i < m; i++){
            psum[i][0] = psum[i - 1][0] + mat[i][0];
        }
        for(int j=1; j < n; j++){
            psum[0][j] = psum[0][j-1] + mat[0][j];
        }

        for(int i=1; i < m; i++){
            for(int j=1; j < n; j++){
                psum[i][j] = (psum[i][j-1] + psum[i-1][j] - psum[i - 1][j - 1] + mat[i][j]);
            }
        }
        for(int i=0; i < m; i++){
            for(int j=0; j < n; j++){
                result[i][j] = psum[min(i + k, m - 1)][min(j + k, n - 1)];
                if(i - k - 1 >= 0)
                    result[i][j] -= psum[max(i - k - 1, 0)][min(j + k, n - 1)];
                if(j - k - 1 >= 0)
                    result[i][j] -= psum[min(i + k, m - 1)][max(j - k - 1, 0)];
                if(i - k - 1 >= 0 && j - k - 1 >= 0)
                    result[i][j] += psum[max(i - k - 1, 0)][max(j - k - 1, 0)];
            }
        }

        return result;

    }
};