class Solution {
public:
    double trimMean(std::vector<int>& arr) {
        std::sort(arr.begin(), arr.end());

        int n = arr.size();
        int trim_count = n * 0.05;
        int sum = 0;
        for (int i = trim_count; i < n - trim_count; ++i) {
            sum += arr[i];
        }
        int remaining_count = n - 2 * trim_count;
        return static_cast<double>(sum) / remaining_count;
    }
};