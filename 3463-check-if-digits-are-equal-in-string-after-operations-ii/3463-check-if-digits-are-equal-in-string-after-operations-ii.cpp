class Solution {
public: 
    int fact[5] = {1, 1, 2, 6, 24};
    vector<vector<int>> nCr_MOD5_Table;
    void precompute_nCr_MOD5() {
        nCr_MOD5_Table.resize(5, vector<int>(5));
        for(int n = 0; n < 5; n++) {
            for(int r = 0; r < 5; r++) {
                if(r > n) nCr_MOD5_Table[n][r] = 0;
                else nCr_MOD5_Table[n][r] = (fact[n] / (fact[r] * fact[n - r])) % 5;
            }
        }
    }
    int nCr_MOD2(int n, int r) {
        while(n > 0 || r > 0) {
            int bitN = n & 1;
            int bitR = r & 1;
            if(bitR > bitN) return 0;
            n >>= 1;
            r >>= 1;
        }
        return 1;
    }
    int nCr_MOD5(int n, int r) {
        int ans = 1;
        while(n > 0 || r > 0) {
            int ni = n % 5;
            int ri = r % 5;
            if(ri > ni) return 0;

            ans = (ans * nCr_MOD5_Table[ni][ri]) % 5;
            n /= 5;
            r /= 5;
        }
        return ans;
    }
    int nCr_MOD10(int n, int r) {
        int a = nCr_MOD2(n, r);
        int b = nCr_MOD5(n, r);
        if(a == 0) return b + 5 * (b & 1);
        else return b + 5 * (!(b & 1));
    }
    int findSum(string& s, int start, int end) {
        int n = s.size();
        int sum = 0;
        int N = n - 2;
        for(int i = start; i <= end; i++) {
            sum = (sum + (s[i] - '0') * nCr_MOD10(N, i - start)) % 10;
        }
        return sum;
    }
    bool hasSameDigits(string s) {
        int n = s.size();
        precompute_nCr_MOD5();
       int sum1 = findSum(s, 0, n - 2);
       int sum2 = findSum(s, 1, n - 1);
        
        return sum1 == sum2;
    }
};