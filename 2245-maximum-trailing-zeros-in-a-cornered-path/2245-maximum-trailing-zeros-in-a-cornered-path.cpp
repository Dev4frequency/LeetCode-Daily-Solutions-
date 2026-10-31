class Custom{
public:
    vector<vector <vector <pair <int, int>>>> vec;
    Custom(int m, int n){
        vec.resize(m, vector <vector <pair <int, int>>>(n, vector <pair <int, int>> (4)));
    }
};

class Solution {
private:
    int dp2[1001];
    int dp5[1001];

    int contri2(int num) {
        if (num == 1 || num % 2 != 0) return 0;
        if (dp2[num] != -1) return dp2[num];
        return dp2[num] = 1 + contri2(num / 2);
    }

    int contri5(int num) {
        if (num == 1 || num % 5 != 0) return 0;
        if (dp5[num] != -1) return dp5[num];
        return dp5[num] = 1 + contri5(num / 5);
    }
public:
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        memset(dp2, -1, sizeof dp2);
        memset(dp5, -1, sizeof dp5);

        Custom ds(m, n);

        //left sweep
        for(int i=0; i<m; i++){
            int curr2 = 0;
            int curr5 = 0;
            for(int j=0; j<n; j++){
                int cell = grid[i][j];
                curr2 += contri2(cell);
                curr5 += contri5(cell);

                ds.vec[i][j][0].first = curr2;
                ds.vec[i][j][0].second = curr5;
            }
        }

        //right sweep
        for(int i=0; i<m; i++){
            int curr2 = 0;
            int curr5 = 0;
            for(int j=n-1; j>=0; j--){
                int cell = grid[i][j];
                curr2 += contri2(cell);
                curr5 += contri5(cell);

                ds.vec[i][j][1].first = curr2;
                ds.vec[i][j][1].second = curr5;
            }
        }

        //top sweep
        for(int i=0; i<n; i++){
            int curr2 = 0;
            int curr5 = 0;
            for(int j=0; j<m; j++){
                int cell = grid[j][i];
                curr2 += contri2(cell);
                curr5 += contri5(cell);

                ds.vec[j][i][2].first = curr2;
                ds.vec[j][i][2].second = curr5;
            }
        }

        //bottom sweep
        for(int i=0; i<n; i++){
            int curr2 = 0;
            int curr5 = 0;
            for(int j=m-1; j>=0; j--){
                int cell = grid[j][i];
                curr2 += contri2(cell);
                curr5 += contri5(cell);

                ds.vec[j][i][3].first = curr2;
                ds.vec[j][i][3].second = curr5;
            }
        }

        int ans = INT_MIN;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int cell = grid[i][j];
                int c2 = contri2(cell);
                int c5 = contri5(cell);
                int poss1 = min(ds.vec[i][j][2].first+ds.vec[i][j][0].first - c2,
                                ds.vec[i][j][2].second+ds.vec[i][j][0].second -c5);
                int poss2 = min(ds.vec[i][j][2].first+ds.vec[i][j][1].first-c2,
                                ds.vec[i][j][2].second+ds.vec[i][j][1].second-c5);
                int poss3 = min(ds.vec[i][j][3].first+ds.vec[i][j][0].first-c2,
                                ds.vec[i][j][3].second+ds.vec[i][j][0].second-c5);
                int poss4 = min(ds.vec[i][j][3].first+ds.vec[i][j][1].first-c2,
                                ds.vec[i][j][3].second+ds.vec[i][j][1].second-c5);

                ans = max({ans, poss1, poss2, poss3, poss4});
            }
        }

        return ans;
    }
};