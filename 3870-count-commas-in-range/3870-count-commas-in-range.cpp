class Solution {
public:
    int countCommas(int n) {
        long long total = 0;
        long long low = 1;
        int digits = 1;
        while (low <= n) {
            long long high = low * 10 - 1;
            long long hi = min<long long>(high, (long long)n);
            long long count = hi - low + 1;
            total += count * ((digits - 1) / 3);
            low *= 10;
            ++digits;
        }
        return (int)total;
    }
};