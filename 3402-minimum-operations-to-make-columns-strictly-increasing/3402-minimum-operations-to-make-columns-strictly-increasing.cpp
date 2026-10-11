class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int count = 0;
        for(int i = 0; i<grid[0].size() ; i++){
            int max_ = grid[0][i];
            for(int j = 1 ; j<grid.size() ; j++){
                if(max_>=grid[j][i]){
                    count+=max_+1-grid[j][i];
                    max_++;
                }
                else{
                    max_ = grid[j][i];
                }
            }
        }
        return count;
    }
};