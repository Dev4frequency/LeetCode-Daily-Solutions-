class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int nodel = arr[0];
        int onedel = INT_MIN;
        int res = arr[0];
        for(int i=1;i<arr.size();i++){
            int prenodel = nodel;
            int preone = onedel;
            nodel = max(nodel+arr[i],arr[i]);
            int v2;
            if(preone == INT_MIN){
                v2 = arr[i];
            }
            else{
                v2 = preone+arr[i];
            }
            onedel = max(v2,prenodel);
            res = max({onedel,res,nodel});
        }
        return res;
    }
};