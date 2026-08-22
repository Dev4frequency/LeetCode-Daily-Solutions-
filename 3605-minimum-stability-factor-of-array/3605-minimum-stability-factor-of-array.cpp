class Solution {
public:
    int minStable(vector<int>& a, int maxC) {           
        int n = a.size(), K = log2(n);
     int f[n+10][K+10];
        memset(f, 0, sizeof(f));

        for (int i = 1; i <= n; i++) f[i][0] = a[i-1];
        for (int k = 1; k <= K; k++) {
            for (int i = 1; i+(1<<k)-1 <= n; i++) f[i][k] = gcd(f[i][k-1], f[i+(1<<k-1)][k-1]);
        }

        int dp[n+10];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= n; i++) {           
            int r = i, val = 0;
            for (int k = K; k >= 0; k--) if (r+(1<<k)-1 <= n && gcd(val,f[r][k]) > 1) val = gcd(val,f[r][k]), r += 1<<k;
            dp[i] = r - i;
        }
        int one = 0;
        for (auto& val : a) one += val == 1;
        if ((n - one) <= maxC) return 0;
        int upp = 0;
        for (int i = 1; i <= n; i++) upp = max(upp, dp[i]);
        if (maxC == 0) return upp;
        auto check = [&](int siz) -> bool {
            int i = 1, tot = 0, val = 0;
            while (i <= n) {
                if (dp[i] <= siz) {
                    i++;
                } else {
                    val = dp[i] / (siz+1);
                    tot += val;
                    i += val*(siz+1);
                }
            }
            return tot <= maxC;
        };

        int l = 1, r = n;
        while (l <= r) {
            int mid = (l+r)>>1;
            if (!check(mid)) l = mid+1;
            else             r = mid-1;
        }
        return l;
    }
};