
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        long long ans = 0;
        long long cost = 0;

        int right = n - 1;
        deque<pair<int, int>> dq;

        for (int left = n - 1; left >= 0; left--) {

            int cnt = 1;
            while (!dq.empty() && dq.front().first <= nums[left]) {
                auto [val, freq] = dq.front();
                dq.pop_front();

                cost += 1LL * (nums[left] - val) * freq;
                cnt += freq;
            }
            dq.push_front({nums[left], cnt});
            while (cost > k) {
                auto& [val, freq] = dq.back();
                cost -= 1LL * (val - nums[right]);
                freq--;

                if (freq == 0) {
                    dq.pop_back();
                }

                right--;
            }
            ans += right - left + 1;
        }
        return ans;
    }
};