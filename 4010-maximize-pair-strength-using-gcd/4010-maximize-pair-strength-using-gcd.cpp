class Solution
{
public:
    long long maxPairStrength(const vector<int>& nums) const
    {
        assert(MIN_LENGTH <= nums.size() && nums.size() <= MAX_LENGTH);

        long long maxStrength = 0;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            assert(MIN_NUM <= nums[i] && nums[i] <= MAX_NUM);
            for (size_t j = i + 1; j < nums.size(); ++j)
            {
                assert(MIN_NUM <= nums[j] && nums[j] <= MAX_NUM);
                const long long g = getGCDRecursive(nums[i], nums[j]);
                const long long strength = (nums[i] / g) * (nums[j] / g);
                maxStrength = max(maxStrength, strength);
            }
        }

        return maxStrength;
    }

private:
    enum
    {
        MIN_LENGTH = 2,
        MAX_LENGTH = 2000,
        MIN_NUM = 1,
        MAX_NUM = 100000
    };

    long long getGCDRecursive(const long long a, const long long b) const
    {
        assert(a > 0 && b >= 0);

        if (b == 0)
        {
            return a;
        }

        return getGCDRecursive(b, a % b);
    }
};
