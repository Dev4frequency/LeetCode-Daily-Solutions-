class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        long long ans = LLONG_MIN;
        if(m == 1) {
            for(auto &x : nums) ans = max(ans, (long long)x*x);
            return ans;
        }

        int n = nums.size();
        set<int> valid;
        for(int i = m-1; i < n; i++) {
            valid.insert(nums[i - (m-1)]);
            int mn = *(valid.begin()), mx = *(valid.rbegin());
            ans = max(ans, (long long)nums[i]*mn);
            ans = max(ans, (long long)nums[i]*mx);
        }

        return ans;
    }
};