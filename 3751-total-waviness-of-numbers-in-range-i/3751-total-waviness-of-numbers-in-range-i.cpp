class Solution {
public:
    int waviness(int x) {
        int d[6];
        int n = 0;

        while (x) {
            d[n++] = x % 10;
            x /= 10;
        }

        if (n < 3) return 0;

        int cnt = 0;

        for (int i = 1; i < n - 1; i++) {
            if ((d[i] > d[i - 1] && d[i] > d[i + 1]) ||
                (d[i] < d[i - 1] && d[i] < d[i + 1])) {
                cnt++;
            }
        }

        return cnt;
    }

    int totalWaviness(int num1, int num2) {
        int ans = 0;

        for (int x = num1; x <= num2; x++) {
            ans += waviness(x);
        }

        return ans;
    }
};