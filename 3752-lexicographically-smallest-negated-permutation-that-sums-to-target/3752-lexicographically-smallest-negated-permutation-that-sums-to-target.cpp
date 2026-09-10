class Solution
{
public:
    vector<int> lexSmallestNegatedPerm(const int n, const long long target) const
    {
        assert(MIN_N <= n && n <= MAX_N);
        assert(MIN_TARGET <= target && target <= MAX_TARGET);

        const long long sumPos = static_cast<long long>(n) * (n + 1) / 2;
        const long long diff = sumPos - target;
        if (diff < 0 || diff % 2 != 0)
        {
            return {};
        }

        long long remain = diff / 2;
        vector<bool> neg(n + 1, false);
        for (int x = n; x >= 1; --x)
        {
            if (remain >= x)
            {
                remain -= x;
                neg[x] = true;
            }
        }

        if (remain != 0)
        {
            return {};
        }

        vector<int> result(n);
        for (int i = 0; i < n; ++i)
        {
            const int x = i + 1;
            result[i] = neg[x] ? -x : x;
        }

        sort(result.begin(), result.end());
        return result;
    }

private:
    enum
    {
        MIN_N = 1,
        MAX_N = 100000,
        MIN_TARGET = -10000000000LL,
        MAX_TARGET = 10000000000LL
    };
};