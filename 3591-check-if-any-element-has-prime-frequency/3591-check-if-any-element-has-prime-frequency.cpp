class Solution 
{
public:
    bool checkPrimeFrequency(vector<int>& nums) 
    {
        assert(MIN_LENGTH <= nums.size() && nums.size() <= MAX_LENGTH);

        unordered_map<int, int> freq;

        for (const auto num : nums)
        {
            assert(MIN_NUM <= num && num <= MAX_NUM);
            ++freq[num];
        }
        
        for (const auto [num, count] : freq)
        {
            if (isPrime(count) == true)
            {
                return true;
            }
        }

        return false;
    }

private:
    bool isPrime(const int n) 
    {
        if (n == 1) return false;
        
        for (int i = 2; i < n; i++) 
        {
            if (n % i == 0) 
            {
                return false;
            }
        }

        return true;
    }

    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        MIN_NUM = 0,
        MAX_NUM = 100,
    };
};