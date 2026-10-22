    class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int i= 0, j, m = colsum.size();
        int k = 0;
        vector<vector<int>> output(2, (vector<int> (m, 0)));
        while(k < m){
            if(upper + lower < colsum[k]){
                 vector<vector<int>> empty;
                return empty;
            }
            if(colsum[k] == 2){
                output[0][i] = 1;
                output[1][i] = 1;
                upper--;
                lower--;
            }else if(colsum[k] == 1){
                if(upper >= lower){
                    output[0][i] = 1;
                    upper--;
                }else{
                    output[1][i] = 1;
                    lower--;
                }
            }
            k++;
            i++;
        }
        if(upper != 0 || lower != 0){
            vector<vector<int>> empty;
            return empty;
        }

        return output;
    }
};