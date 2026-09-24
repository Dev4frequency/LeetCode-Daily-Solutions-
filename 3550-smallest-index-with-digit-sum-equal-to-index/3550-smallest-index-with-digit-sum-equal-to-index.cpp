class Solution {
public:
    int sumd(int x) {
        int sum = 0;

        while (x > 0) {
            sum += (x % 10);
            x = x / 10;
        }

        return sum;
    }

    int smallestIndex(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (i == sumd(nums[i])) {
                return i;
            }
        }

        return -1;
    }
};