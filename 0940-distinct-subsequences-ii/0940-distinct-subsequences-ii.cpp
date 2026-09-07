class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;
        vector<long long> last(26, 0);
        long long dp = 1;
        for (char ch : s) {
            int c = ch - 'a';
            long long prev = dp;
            dp = (2 * dp - last[c] + MOD) % MOD;
            last[c] = prev;
        }
        return (int)((dp - 1 + MOD) % MOD);
    }
};