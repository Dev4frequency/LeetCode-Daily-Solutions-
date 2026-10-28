class Solution {
public:
    int maxRow(vector<vector<int>>& mat,int j){
        int maxi = INT_MIN;
        int ind = -1;
        for(int i=0;i<mat.size();i++){
            if(mat[i][j]>maxi){
                maxi = mat[i][j];
                ind = i;
            }
        }
        return ind;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int low = 0, high = m-1,mid;
        while(low<=high){
            mid = (low+high)/2;
            int i = maxRow(mat,mid);
            int left = (mid > 0) ? mat[i][mid-1] : -1;
            int right = (mid < m-1) ? mat[i][mid+1] : -1;

            if(mat[i][mid] > left && mat[i][mid] > right){
                return {i, mid};
            }
            else if(mat[i][mid] < right){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return {-1,-1};
    }
};