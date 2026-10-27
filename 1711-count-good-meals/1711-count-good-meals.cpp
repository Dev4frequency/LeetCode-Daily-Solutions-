class Solution {
public:
    int countPairs(vector<int>& deliciousness) {

        unordered_map<int, int> freq;

        const int MOD = 1e9 + 7;

        long long ans = 0;

        for (int num : deliciousness) {

            for (int power = 1; power <= (1 << 21); power <<= 1) {

                int need = power - num;

                if (freq.count(need))
                    ans = (ans + freq[need]) % MOD;
            }

            freq[num]++;
        }

        return ans;
    }
};