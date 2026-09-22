class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0)
            return false;

        unordered_map<int, int> mp;
        for (int x : nums) {
            mp[x]++;
        }

        int grp = n / k;
        for (auto& x : mp) {
            if (x.second > grp) {
                return false;
            }
        }
        return true;
    }
};