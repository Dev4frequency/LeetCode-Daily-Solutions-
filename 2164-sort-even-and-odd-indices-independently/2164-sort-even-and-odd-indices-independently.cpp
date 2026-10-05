class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odd;
        vector<int> even;

        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                even.push_back(nums[i]);
            } else {
                odd.push_back(nums[i]);
            }
        }

        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end(), greater<int>());

        for (int i = 0; i < nums.size(); i += 2) {
            nums[i] = even[i / 2];
            if (i + 1 < nums.size()) {
                nums[i + 1] = odd[i / 2];
            }
        }

        return nums;
    }
};