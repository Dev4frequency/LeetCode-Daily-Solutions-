class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int i = 0, j = 0;
        int n = nums.size();
        int count = 0;
        int f = 0;

        while (j < n) {
            if (nums[j] > right) {
                i = j + 1;
                f = 0;
            }
            else if (nums[j] >= left) {
                f = j - i + 1;
                count += f;
            }
            else {
                count += f;
            }
            j++;
        }

        return count;
    }
};