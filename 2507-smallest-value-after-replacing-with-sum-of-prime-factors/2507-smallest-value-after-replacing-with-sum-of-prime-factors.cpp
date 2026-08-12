class Solution {
public:
    int smallestValue(int n) {
        vector<int> spf(n + 1);
        for (int i = 2; i <= n; ++i) spf[i] = i;
        for (int i = 2; i * i <= n; ++i) {
            if (spf[i] == i) {
                for (int j = i * i; j <= n; j += i) {
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }
        while (true) {
            int sum = 0, temp = n;
            while (temp > 1) {
                sum += spf[temp];
                temp /= spf[temp];
            }
            if (sum == n) break;
            n = sum;
        }
        return n;
    }
};