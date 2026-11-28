class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        long long cheapestPrice = items[0][1];
        for (const auto& item : items) {
            cheapestPrice = min(cheapestPrice, (long long)item[1]);
        }

        vector<int> factorCount(n + 1, 0);
        for (const auto& item : items) {
            factorCount[item[0]]++;
        }
        vector<int> multipleCount(n + 1, 0);
        for (int factor = 1; factor <= n; factor++) {
            for (int multiple = factor; multiple <= n; multiple += factor) {
                multipleCount[factor] += factorCount[multiple];
            }
        }
        vector<pair<long long, long long>> slots;
        for (const auto& item : items) {
            long long price = item[1];
            if (price >= 2 * cheapestPrice) {
                continue;
            }

            long long freeCopies = (long long)multipleCount[item[0]] - 1;
            if (freeCopies > 0) {
                slots.emplace_back(price, freeCopies);
            }
        }
        sort(slots.begin(), slots.end());
long long remaining = budget;
        long long doubledCopies = 0;
        for (const auto& slot : slots) {
            long long price = slot.first;
            long long available = slot.second;
            long long take = min(available, remaining / price);

            doubledCopies += take;
            remaining -= take * price;

            if (remaining < price) {
                break;
            }
        }
        long long answer = 2 * doubledCopies + remaining / cheapestPrice;
        return (int)answer;
    }
};