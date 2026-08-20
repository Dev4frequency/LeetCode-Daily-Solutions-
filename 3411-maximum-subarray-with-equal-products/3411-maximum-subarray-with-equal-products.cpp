class Solution {
public:
    int maxLength(vector<int>& nums) {
        vector<int> keys = {0, 0, 2, 4, 2, 16, 6, 64, 2, 4, 18};
        int left = 0, right = 0, n = nums.size();
        int curr = 0;
        int res = 2;
        while (right < n) {
            int key = keys[nums[right++]];
            while ((curr & key) > 0) {
                curr -= keys[nums[left++]];
            }
            curr |= key;
            res = max(res, right - left);
        }
        return res;
    }
};