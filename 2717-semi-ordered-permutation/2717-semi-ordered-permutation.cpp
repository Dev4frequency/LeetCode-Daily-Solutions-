class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();
        if (nums[0] == 1 && nums[n - 1] == n) {
            return 0;
        }

        int oneIndex = 0, lastIndex = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                oneIndex = i;
            } else if (nums[i] == n) {
                lastIndex = i;
            }
        }
        if (oneIndex <= lastIndex) {
            return oneIndex + (n - 1 - lastIndex);
        }
        return oneIndex + (n - 1 - lastIndex) - 1;
    }
};