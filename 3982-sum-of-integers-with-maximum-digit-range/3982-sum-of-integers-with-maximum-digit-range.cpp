class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        vector<int> digit_range;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            vector<int> digits;
            int temp = nums[i];
            while (temp > 0) {
                digits.push_back(temp % 10);
                temp = temp / 10;
            }
            int max = *max_element(digits.begin(), digits.end());
            int min = *min_element(digits.begin(), digits.end());
            digit_range.push_back(max - min);
            digits.clear();
        }

        int max_range = *max_element(digit_range.begin(), digit_range.end());

        for (int i = 0; i < nums.size(); ++i) {
            if (digit_range[i] == max_range) {
                sum += nums[i];
            }
        }
        return sum;
    }
};