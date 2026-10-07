class Solution {
private:
    int getLen(int n){
        if(n == 0){
            return 1;
        }
        int len = 0;
        if(n < 0){
            n = abs(n);
            len++;
        }
        while(n > 0){
            len++;
            n /= 10;
        }
        return len;
    }
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> ans(cols, 0); 

        for(int j = 0; j < cols; j++){  
            int m = 0;
            for(int i = 0; i < rows; i++){
                m = max(m, getLen(grid[i][j]));
            }
            ans[j] = m;
        }
        return ans;
    }
};