class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());
        for (int m = k; ; m += k) {
            if (!s.count(m)) return m;
        }
    }
};