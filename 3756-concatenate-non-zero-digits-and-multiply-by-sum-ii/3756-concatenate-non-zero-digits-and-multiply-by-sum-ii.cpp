class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long MOD = 1e9+7;
        int m = s.size();
        vector<long long> prefSum(m+1,0);
        vector<long long> prefVal(m+1,0);
        vector<long long> pow10(m+1,1); 
        vector<int> cnt(m+1,0);
        
        for(int i=0;i<m;i++){
            int d = s[i]-'0';
            prefSum[i+1] = prefSum[i] + (d!=0? d:0);
            cnt[i+1] = cnt[i] + (d!=0?1:0);
            if(d!=0){
                prefVal[i+1] = (prefVal[i]*10 + d) % MOD;
            } else {
                prefVal[i+1] = prefVal[i];
            }
            pow10[i+1] = (pow10[i]*10) % MOD;
        }
        
        int q = queries.size();
        vector<int> ans(q);
        for(int i=0;i<q;i++){
            int l = queries[i][0], r = queries[i][1];
            long long sum = prefSum[r+1] - prefSum[l];
            int nonzeroInRange = cnt[r+1]-cnt[l];
            long long x;
            if(nonzeroInRange==0){
                x = 0;
            } else {
                long long valFull = prefVal[r+1];
                long long valBefore = prefVal[l];
                long long p = pow10[nonzeroInRange];
                x = ( (valFull - (valBefore*p)%MOD) % MOD + MOD ) % MOD;
            }
            long long res = (x % MOD) * (sum % MOD) % MOD;
            ans[i] = (int)res;
        }
        return ans;
    }
};