class Solution {
public:
    bool helper(vector<int>& matchsticks, int index, vector<long long>& sums,
                long long needSum) {
        if (index == matchsticks.size())
            return all_of(sums.begin(), sums.end(),
                          [&](long long lm) { return lm == needSum; });

        for (int i = 0; i < 4; i++) {
            if (sums[i] + matchsticks[index] <= needSum) {
                sums[i] += matchsticks[index];
                if (helper(matchsticks, index + 1, sums, needSum))
                    return true;

                sums[i] -= matchsticks[index];
            }
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        unsigned long long sum =
            accumulate(matchsticks.begin(), matchsticks.end(), 0ULL);

        if (sum % 4 != 0)
            return false;

        sum /= 4;

        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        vector<long long> sums(4);
        return helper(matchsticks, 0, sums, sum);
    }
};