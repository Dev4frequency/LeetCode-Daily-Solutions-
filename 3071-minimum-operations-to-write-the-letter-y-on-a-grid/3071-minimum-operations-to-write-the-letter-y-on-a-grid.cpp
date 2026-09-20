class Solution {
public:
    bool isYRow(int x, int y, int n) {
        return (x >= n/2 && y == n/2) || (x == y && x <= n/2) || (x+y == (n-1) && x <= n/2);
    }
    void count(int &a, int &b, int &c, int ch) {
        if(ch == 0)
            a++;
        else if(ch == 1)
            b++;
        else
            c++;
    }
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = (int)grid.size();   
        int c0 = 0, c1 = 0, c2 = 0;
        int cy0 = 0, cy1 = 0, cy2 = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isYRow(i,j,n)) {
                    count(cy0, cy1, cy2, grid[i][j]);
                } else {
                    count(c0, c1, c2, grid[i][j]);
                }
            }
        }
       
        int val1 = (cy0+cy1+cy2) - cy0 + (c0+c1+c2) - max(c1, c2);
        int val2 = (cy0+cy1+cy2) - cy1 + (c0+c1+c2) - max(c0, c2);
        int val3 = (cy0+cy1+cy2) - cy2 + (c0+c1+c2) - max(c0, c1);
        int mini = min(val1, min(val2, val3));
        return mini;
    }
};