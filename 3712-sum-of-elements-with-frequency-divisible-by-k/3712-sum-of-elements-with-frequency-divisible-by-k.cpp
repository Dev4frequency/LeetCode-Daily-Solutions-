class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp1;
        for (int it : nums) mp1[it]++;
        
        long long sum = 0;
        for (auto &it : mp1) {
            if (it.second % k == 0) {
                sum += (1LL * it.first * it.second);
            }
        }
        return (int)sum;
    }
};