#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        vector<int> sa(n), rk(n), tmp(n);
        iota(sa.begin(), sa.end(), 0);
        for (int i = 0; i < n; ++i) rk[i] = nums[i];

        for (int k = 1; k < n; k <<= 1) {
            auto cmp = [&](int i, int j) {
                if (rk[i] != rk[j]) return rk[i] < rk[j];
                int ri = (i + k < n) ? rk[i + k] : -1;
                int rj = (j + k < n) ? rk[j + k] : -1;
                return ri < rj;
            };
            sort(sa.begin(), sa.end(), cmp);

            tmp[sa[0]] = 0;
            for (int i = 1; i < n; ++i) {
                tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
            }
            rk = tmp;
            if (rk[sa[n - 1]] == n - 1) break;
        }
        vector<int> lcp(n - 1, 0);
        int h = 0;
        for (int i = 0; i < n; ++i) {
            if (rk[i] == n - 1) {
                h = 0;
                continue;
            }
            int j = sa[rk[i] + 1];
            while (i + h < n && j + h < n && nums[i + h] == nums[j + h]) {
                ++h;
            }
            lcp[rk[i]] = h;
            if (h > 0) --h;
        }
        int min_len = n;
        for (int i = 0; i < n; ++i) {
            int max_lcp = 0;
            if (i > 0) max_lcp = max(max_lcp, lcp[i - 1]);
            if (i < n - 1) max_lcp = max(max_lcp, lcp[i]);
            if (sa[i] + max_lcp < n) {
                min_len = min(min_len, max_lcp + 1);
            }
        }

        return min_len;
    }
};