class Solution {
public:
    int minimumIncrements(const vector<int>& nums, vector<int>& target) {
        sort(target.begin(), target.end());
        int tgte = 0;
        for (int i = 1; i < target.size(); ++i) {
            if (target[i] > target[tgte]) {
                ++tgte;
                swap(target[i], target[tgte]);
            }
        }
        target.resize(tgte + 1);

        const int N = target.size();
        const int kMaskEnd = 1 << N;
        vector<long long> mask2lcm(kMaskEnd, 1);
        for (int m = 1; m < kMaskEnd; ++m) {
            long long lcm = 1;
            for (int i = 0; i < N; ++i)
                if ((m >> i) & 1)
                    lcm = ::lcm<long long>(lcm, target[i]);
            mask2lcm[m] = lcm;
        }
        vector<long long> dp_mask2minc(kMaskEnd, kInf);
        vector<long long> up_mask2minc(kMaskEnd, kInf);
        dp_mask2minc[0] = up_mask2minc[0] = 0;

        long long res = kInf;

        for (int num : nums) {
            for (int mask = 1; mask < kMaskEnd; ++mask) {
                long long mask_minc = up_mask2minc[mask];
                for (int subm = mask; subm; subm = (subm - 1) & mask) {
                    long long lcm = mask2lcm[subm];
                    long long n = (num - 1) / lcm + 1;
                    mask_minc = min(
                        mask_minc,
                        dp_mask2minc[mask ^ subm]
                           + n * lcm - num);
                }
                up_mask2minc[mask] = mask_minc;
            }
            dp_mask2minc = up_mask2minc;
            res = min(res, dp_mask2minc.back());
        }

        return res;
    }

private:
    static constexpr long long kInf = numeric_limits<long long>::max() / 4;
};