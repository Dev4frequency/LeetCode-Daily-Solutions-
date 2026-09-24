class Solution {
public:
    int sumOfFlooredPairs(vector<int>& A) {
        long mod = 1e9 + 7, N = A.size(), ans = 0;
        sort(begin(A), end(A));
        for (int i = 0; i < N; ) {
            long j = i + 1;
            while (j < N && A[j] == A[j - 1]) ++j;
            long dup = j - i;
            ans = (ans + dup * dup % mod) % mod;
            while (j < N) {
                long div = A[j] / A[i], bound = A[i] * (div + 1);
                long next = lower_bound(begin(A) + j, end(A), bound) - begin(A);
                ans = (ans + (next - j) * div % mod * dup % mod) % mod;
                j = next;
            }
            i += dup;
        }
        return ans;
    }
};