class Solution {
public:
    int unequalTriplets(vector<int>& nums) {

        unordered_map<int, int> freq;

        for (int num: nums)  freq[num]++;

        int n = nums.size();
        int ans = 0, left = 0;

        for (auto &[num, f]: freq) {
            int right = n - left - f;
            ans += left * f * right;
            left += f;
        }

        return ans;
    }
};