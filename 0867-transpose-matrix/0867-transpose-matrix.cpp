#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) 
    {
        int m = A.size();
        if (m == 0) return {};
        int n = A[0].size();
        
        vector<vector<int>> B(n, vector<int>(m));
        
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                B[j][i] = A[i][j];
            }
        }
        
        return B;
    }
};