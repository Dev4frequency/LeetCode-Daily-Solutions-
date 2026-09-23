class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<int, int> mp;
        vector<int> result;
        int limit = cbrt(n);
        for (int i = 1; i <= limit; i++) {
            for (int j = i; j <= limit; j++) {
                long long sum = 1LL * i * i * i + 1LL * j * j * j;
                if (sum > n)
                    break;
                mp[sum]++;
            }
        }
        for (auto& it : mp) {
            if (it.second >= 2) {
                result.push_back(it.first);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};