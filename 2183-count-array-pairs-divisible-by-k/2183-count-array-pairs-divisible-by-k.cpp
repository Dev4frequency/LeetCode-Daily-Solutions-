typedef long long ll;

class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<ll, ll> gcdMap;
        ll totalCount = 0;
        
        for (ll i = 0; i < nums.size(); ++i) {
            ll currentGCD = __gcd(nums[i], k);
            for (const auto &[gcdValue, occurrences] : gcdMap) {
                if ((currentGCD * gcdValue) % k == 0) {
                    totalCount += occurrences;
                }
            }
            gcdMap[currentGCD]++;
        }
        
        return totalCount;
    }
};