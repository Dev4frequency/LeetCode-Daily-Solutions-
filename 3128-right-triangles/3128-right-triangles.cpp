#include <vector>
using namespace std;

class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long count = 0;
        if (m == 0 || n == 0) return 0;
        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rowCount[i] += grid[i][j];
                colCount[j] += grid[i][j];
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    if (rowCount[i] > 1 && colCount[j] > 1) {
                        count += (rowCount[i] - 1) * (colCount[j] - 1);
                    }
                }
            }
        }
        return count;
    }
};