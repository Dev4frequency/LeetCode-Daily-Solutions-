class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }

        int reverse;
        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            reverse = 0;

            while (val > 0) {
                reverse = reverse * 10 + val % 10;
                val = val / 10;
            }

            s.insert(reverse);
        }

        return s.size();
    }
};