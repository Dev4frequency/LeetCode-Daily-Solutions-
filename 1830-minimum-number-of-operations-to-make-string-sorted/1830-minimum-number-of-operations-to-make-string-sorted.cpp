class Solution {
    int mod = 1e9 + 7;

    int binExp(int a, int b) {
        int ans = 1;

        while (b > 0) {
            if (b & 0x01) {
                ans = 1LL * ans * a % mod;
            }

            a = 1LL * a * a % mod;
            b >>= 1;
        }

        return ans;
    }
public:
    int makeStringSorted(string s) {
        int n = s.size();
        vector<int> fact(n + 1), finv(n + 1);
        fact[0] = finv[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = 1LL * fact[i - 1] * i % mod;
            finv[i] = binExp(fact[i], mod - 2);
        }

        int rank = 1;
        vector<int> freq(26);
        for (int i = n - 1; i >= 0; i--) {
            int idx = s[i] - 'a';
            freq[idx]++;

            long perms = fact[n - 1 - i];
            for (int j = 0; j < 26; j++) {
                if (freq[j] > 0) {
                    perms = perms * finv[freq[j]] % mod;
                }
            }

            for (int j = 0; j < idx; j++) {
                rank = (rank + freq[j] * perms) % mod;
            }
        }

        return rank - 1;
    }
};