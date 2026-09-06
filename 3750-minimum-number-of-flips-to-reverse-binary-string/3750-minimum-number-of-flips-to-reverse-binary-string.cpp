class Solution
{
public:
    int minimumFlips(int n) const
    {
        assert(MIN_N <= n && n <= MAX_N);

        string bits;
        bits.reserve(INT_BIT_LENGTH);

        while (n > 0)
        {
            const int bit = n & 1;
            bits.push_back(static_cast<char>('0' + bit));
            n >>= 1;
        }

        const size_t LEN = bits.size();
        int flipCount = 0;

        for (size_t i = 0; i < LEN; ++i)
        {
            const char originalBit = bits[LEN - 1 - i];
            if (bits[i] != originalBit)
            {
                ++flipCount;
            }
        }

        assert(flipCount >= 0);
        return flipCount;
    }

private:
    enum
    {
        MIN_N = 1,
        MAX_N = 1000000000,
        INT_BIT_LENGTH = 32,
    };
};