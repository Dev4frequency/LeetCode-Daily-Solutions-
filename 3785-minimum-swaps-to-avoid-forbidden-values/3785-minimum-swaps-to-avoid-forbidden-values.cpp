class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        map<int, int> mp;
        int n = nums.size();
        for (int x : nums) mp[x]++;
        for (int x : forbidden) mp[x]++;
        for (auto [val, cnt] : mp) {
            if (cnt > n) {
                return -1;
            }
        }
        int conflicts = 0;
        map<int, int> equalconflicts;
        for (int i = 0; i < n; i++) {
            if (nums[i] == forbidden[i]) {
                conflicts++;
                equalconflicts[nums[i]]++;
            }
        }
        int u = 0;
        for (auto [val, cnt] : equalconflicts) {
            u = max(u, cnt);
        }
        int v = (conflicts + 1) / 2;

        return max(u, v);
    }
};