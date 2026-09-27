class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> ans(img.size(),vector<int>(img[0].size(),0));
        int m=img.size();
        int n=img[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int len=1;
                int avg=img[i][j];
                if((i-1>=0)){
                    avg+=img[i-1][j];
                    len++;
                }
                if((i+1)<m){
                    avg+=img[i+1][j];
                    len++;
                }
                if(j-1>=0){
                    avg+= img[i][j-1];
                    len++;
                }
                if(j+1<n){
                    avg+=img[i][j+1];
                    len++;
                }
                if((i-1>=0) && (j-1>=0)){
                    avg+=img[i-1][j-1];
                    len++;
                }
                if((i-1)>=0 && (j+1)<n){
                    avg+=img[i-1][j+1];
                    len++;
                }
                if((i+1)<m && (j-1)>=0){
                    avg+=img[i+1][j-1];
                    len++;
                }
                if((i+1)<m && (j+1)<n){
                    len++;
                    avg+=img[i+1][j+1];
                }
                ans[i][j]=floor(avg/len);
            }
        }
        return ans;
    }
};