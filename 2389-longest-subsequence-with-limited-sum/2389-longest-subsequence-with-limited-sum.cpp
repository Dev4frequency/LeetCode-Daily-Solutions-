class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int> ans(m);
        sort(nums.begin(), nums.end());
        vector<int> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] = nums[i] + pre[i - 1];
        }
        for (int i = 0; i < m; i++) {
            ans[i] = upper_bound(pre.begin(), pre.end(), queries[i]) - pre.begin();
        }
        return ans;
    }
};