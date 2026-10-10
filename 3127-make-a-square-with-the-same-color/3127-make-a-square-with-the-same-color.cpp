class Solution {
public:
    bool checkSquare(vector<vector<char>>& grid, int iStart, int iEnd, int jStart, int jEnd){
        int bCount = 0, wCount = 0;
        for(int i = iStart; i <= iEnd; i++){
          for(int j = jStart; j <= jEnd; j++){
            if(grid[i][j] == 'B') bCount++;
              else wCount++;
          }  
        }
        return bCount-wCount != 0 ;
    }
    bool canMakeSquare(vector<vector<char>>& grid) {
        return checkSquare(grid,0,1,0,1) || checkSquare(grid,1,2,0,1) || checkSquare(grid,0,1,1,2) || checkSquare(grid,1,2,1,2);
    }
};