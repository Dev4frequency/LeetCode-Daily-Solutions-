class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int maxi = INT_MIN;
        int mini = INT_MAX;

        int maxIdx = -1;
        int minIdx = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] > maxi) {
                maxi = nums[i];
                maxIdx = i;
            }

            if (nums[i] < mini) {
                mini = nums[i];
                minIdx = i;
            }
        }
        int x = min(maxIdx, minIdx);
        int y = max(maxIdx, minIdx);

        int ans = min({
            y + 1,
            n - x,
            x + 1 + n - y
        });

        return ans;
    }
};