class Solution {
public:
    int minMoves(vector<int>& a, int l) {
        int n = a.size(), ans = n, cur = 0;
        vector<int> d(2 * l + 2);

        for (int i = 0; i < n / 2; i++) {
            int x = min(a[i], a[n - 1 - i]), y = max(a[i], a[n - 1 - i]);
            d[2] += 2;
            d[x + 1]--;
            d[x + y]--;
            d[x + y + 1]++;
            d[y + l + 1]++;
        }

        for (int s = 2; s <= 2 * l; s++) {
            cur += d[s];
            ans = min(ans, cur);
        }
        return ans;
    }
};