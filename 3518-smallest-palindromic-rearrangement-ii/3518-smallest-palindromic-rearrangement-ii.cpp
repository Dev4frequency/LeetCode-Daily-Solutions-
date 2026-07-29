class Solution {
public:
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string half;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            half += string(freq[i] / 2, 'a' + i);

            if (freq[i] % 2)
                mid = 'a' + i;
        }

        int m = half.size();
        auto countWays = [&](vector<int>& cnt) {
            long long ways = 1;
            int remaining = 0;

            for (int x : cnt)
                remaining += x;

            for (int x : cnt) {
                for (int j = 1; j <= x; j++) {
                    ways = ways * (remaining - x + j) / j;

                    if (ways >= k)
                        return (long long)k;

                }
                remaining -= x;
            }

            return ways;
        };

        vector<int> cnt(26);

        for (int i = 0; i < 26; i++)
            cnt[i] = freq[i] / 2;

        string left;
        for (int pos = 0; pos < m; pos++) {

            for (int c = 0; c < 26; c++) {

                if (cnt[c] == 0)
                    continue;

                cnt[c]--;

                long long ways = countWays(cnt);

                if (ways >= k) {
                    left += char('a' + c);
                    break;
                }

                k -= ways;
                cnt[c]++;
            }
        }
        
        if ((int)left.size() != m)
            return "";

        string right = left;
        reverse(right.begin(), right.end());

        if (mid)
            return left + mid + right;

        return left + right;
    }
};