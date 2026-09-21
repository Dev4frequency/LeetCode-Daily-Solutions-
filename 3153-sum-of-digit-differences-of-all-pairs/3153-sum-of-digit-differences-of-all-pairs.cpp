class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();
        int d = to_string(nums[0]).size();  // All numbers have the same number of digits
        vector<string> strNums(n);

        // Convert all numbers to strings
        for (int i = 0; i < n; ++i) {
            strNums[i] = to_string(nums[i]);
        }

        long long total = 0;

        // For each digit position
        for (int pos = 0; pos < d; ++pos) {
            vector<int> count(10, 0);  // Count of digits 0-9 at current position
            for (int i = 0; i < n; ++i) {
                int digit = strNums[i][pos] - '0';
                count[digit]++;
            }
            for (int digit = 0; digit < 10; ++digit) {
                total += (long long)count[digit] * (n - count[digit]);
            }
        }

        return total / 2;
    }
};