class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();
        vector<vector<char>>v(m, vector<char>(n, '.'));

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                v[j][i] = boxGrid[i][j];
            }
        }

        for(int i = 0; i<m; i++){
            reverse(v[i].begin(), v[i].end());
        }
         for(int i = 0; i<n; i++){
            int dot = m-1;
            for(int j = m-1; j>=0; j--){
                if(v[j][i]=='*'){dot = j-1;}
                else if(v[j][i]=='#'){
                   v[j][i]='.'; v[dot][i]='#'; dot--;
                }
            }
        }
        return v;
  
    }
};