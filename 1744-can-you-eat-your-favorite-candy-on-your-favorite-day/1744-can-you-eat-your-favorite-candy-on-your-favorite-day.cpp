class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();
        vector<long long> prefixSum(n, 0);
        prefixSum[0] = candiesCount[0];
        for (int i = 1; i < n; ++i) 
            prefixSum[i] = prefixSum[i - 1] + (long long)candiesCount[i];

        vector<bool> result;
        for (const auto& query : queries) {
            int type = query[0];
            long long day = query[1], dailyCap = query[2];
            long long minDay = (type == 0) ? 0 : prefixSum[type - 1];
            long long maxDay = prefixSum[type] - 1;
            long long earliestEatDay = day;
            long long latestEatDay = (day + 1) * dailyCap - 1;
            result.push_back(earliestEatDay <= maxDay && latestEatDay >= minDay);
        }
        return result;
    }
};