class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        for(int i=0; i<n; i++){
           int k=rowShift[i]%n;
           while(k>0){
            int val=grid[i][0];
            for(int j=0; j<n-1; j++){
                grid[i][j]=grid[i][j+1];
            }
               grid[i][n-1]=val;
               k--;
           }
        
        }
        for(int i=0; i<n; i++){
           int k=colShift[i]%n;
           while(k>0){
            int val=grid[0][i];
            for(int j=0; j<n-1; j++){
                grid[j][i]=grid[j+1][i];
            }
               grid[n-1][i]=val;
               k--;
           }
          
        }
        return grid;
    }
};