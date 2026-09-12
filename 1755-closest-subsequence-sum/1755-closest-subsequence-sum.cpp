class Solution {
public:
    void generate(vector<int>& nums, int index, int end,
                  long long sum, vector<long long>& sums) {
        if (index == end) {
            sums.push_back(sum);
            return;
        }
        generate(nums, index + 1, end, sum, sums);
        generate(nums, index + 1, end,
                 sum + nums[index], sums);
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int mid = n / 2;
        vector<long long> leftSums;
        vector<long long> rightSums;
        generate(nums, 0, mid, 0, leftSums);
        generate(nums, mid, n, 0, rightSums);
        sort(rightSums.begin(), rightSums.end());
        long long ans = LLONG_MAX;
        for (long long left : leftSums) {
            long long needed = (long long)goal - left;
            auto it = lower_bound(rightSums.begin(),
                                  rightSums.end(),
                                  needed);
            if (it != rightSums.end()) {
                ans = min(ans, abs(left + *it - goal));
            }
            if (it != rightSums.begin()) {
                --it;
                ans = min(ans, abs(left + *it - goal));
            }
        }
        return (int)ans;
    }
};