class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {

        for(int i = 0; i < matrix.size() - 1; i++){

            if(matrix[i].size() != matrix[i + 1].size()) return false;

            for(int j = 0; j < matrix[i + 1].size() - 1; j++){
                if (matrix[i][j] != matrix[i + 1][j + 1]){
                    return false;
                }
            }

        }
        return true;
    }
};