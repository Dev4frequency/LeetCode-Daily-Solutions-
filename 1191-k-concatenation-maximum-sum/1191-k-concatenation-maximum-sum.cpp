#define MOD (1'000'000'000 + 7)

class Solution {
public:
    int kConcatenationMaxSum(vector<int> &arr, int k) {
        long total_sum, min_sum, max_sum;
        total_sum = min_sum = max_sum = 0;
        for (int i = 0; i < arr.size(); ++i) {
            total_sum += arr[i];
            min_sum = min(total_sum, min_sum);
            max_sum = max(total_sum - min_sum, max_sum);
        }
        if (k == 1 || max_sum == 0)
            return max_sum;
        long onepass_sum = total_sum;
        //using kaden's algo twice
        for (int i = 0; i < arr.size(); ++i) {
            total_sum += arr[i];
            min_sum = min(total_sum, min_sum);
            max_sum = max(total_sum - min_sum, max_sum);
        }
        if (k == 2 || onepass_sum < 0)
            return max_sum % MOD;
        return (max_sum + (k - 2) * onepass_sum) % MOD;
    }
};