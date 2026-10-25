class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        const int MOD = 1e9 + 7;
        sort(inventory.begin(), inventory.end(), greater<int>());
        inventory.push_back(0);

        long long profit = 0;
        int n = inventory.size();

        for (int i = 0; i < n - 1 && orders > 0; ++i) {
            int curr = inventory[i];
            int next = inventory[i + 1];
            int count = i + 1;

            long long levels = curr - next;
            long long totalBalls = levels * count;

            if (orders >= totalBalls) {
                long long sum = (long long)(curr + next + 1) * levels / 2;
                profit = (profit + sum * count) % MOD;
                orders -= totalBalls;
            } else {
                long long fullLevels = orders / count;
                long long remainder = orders % count;
                int low = curr - fullLevels;

                long long sum = (long long)(curr + low + 1) * fullLevels / 2;
                profit = (profit + sum * count) % MOD;
                profit = (profit + (long long)remainder * (low)) % MOD;
                break;
            }
        }

        return profit;
    }
};