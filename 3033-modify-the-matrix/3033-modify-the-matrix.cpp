class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
     for(int i = 0;i<matrix[0].size();++i){
            int mx= -1;
            for(int j = 0;j<matrix.size();++j){
                mx=max(mx,matrix[j][i]);
            }
            for(int j = 0;j<matrix.size();++j){
                matrix[j][i]=matrix[j][i]==-1? mx:matrix[j][i];
            }
        }
        return matrix;
    }
};