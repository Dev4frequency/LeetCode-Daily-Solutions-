class Solution {
public:
    int arrayNesting(vector<int>& A) {
        int res = 0, n = A.size();
        for (int i = 0; i < n; i++) {
            if (A[i] >= 0) {
                int cnt = 0;
                while (A[i] >= 0) {
                    int temp = i;
                    i = A[i];
                    A[temp] = -1;
                    cnt++;
                }
                res = max(res, cnt);
            }
        }
        return res;  
    }
};