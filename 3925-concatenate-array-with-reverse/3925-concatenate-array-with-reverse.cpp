class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> result = nums;

        for (int i = nums.size() - 1; i >= 0; i--) {
            result.push_back(nums[i]);
        }

        return result;
    }
};