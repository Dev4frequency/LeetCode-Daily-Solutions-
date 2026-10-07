class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int ans = -1, mx_cnt = -1;
        for (auto d : divisors) {
            int cnt = 0;
            for (auto x : nums) {
                if (x % d == 0) {
                    cnt += 1;
                }
            }
            if (cnt > mx_cnt) {
                mx_cnt = cnt;
                ans = d;
            } else if (cnt == mx_cnt) {
                ans = min(ans, d);
            }
        }
        return ans;
    }
};