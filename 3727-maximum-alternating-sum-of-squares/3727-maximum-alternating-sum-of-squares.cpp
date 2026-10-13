class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });
        deque<int> dq(nums.begin(), nums.end());
        vector<int> arr;
        bool pickLarge = true;
        while (!dq.empty()) {
            if (pickLarge) {
                arr.push_back(dq.back());
                dq.pop_back();
            } else {
                arr.push_back(dq.front());
                dq.pop_front();
            }
            pickLarge = !pickLarge;
        }
        long long score = 0;
        for (int i = 0; i < n; i++) {
            long long sq = 1LL * arr[i] * arr[i];
            if (i % 2 == 0) score += sq;
            else score -= sq;
        }

        return score;
    }
};