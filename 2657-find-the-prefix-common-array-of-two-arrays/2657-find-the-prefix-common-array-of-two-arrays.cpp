class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int n=A.size();
        map<int,int> mpp;
        vector<int> vec;
        for(int i=0;i<n;i++){
            int cnt=0;
            mpp[A[i]]++;
            mpp[B[i]]++;
            for(auto it: mpp){
                if(it.second>=2){
                    cnt++;
                }
            }
            vec.push_back(cnt);

        }
        return vec;
    }
};