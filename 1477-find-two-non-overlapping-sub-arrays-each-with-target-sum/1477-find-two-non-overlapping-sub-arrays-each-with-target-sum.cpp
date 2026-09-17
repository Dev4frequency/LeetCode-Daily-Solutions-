class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;
        vector<int> prefix(n, INF);
        vector<int> suffix(n, INF);
        int best = INF;
        int left = 0;
        int sum = 0;
 
        // Left to right pass: shortest valid subarray ending at or before 'right'
        for (int right = 0; right < n; right++) {
            sum += arr[right];
            while (sum > target) {
                sum -= arr[left];
                left += 1;
            }
            if (sum == target) {
                best = min(best, right - left + 1);
            }
            prefix[right] = best;
        }
 
        best = INF;
        left = n - 1;
        sum = 0;
 
        // Right to left pass: shortest valid subarray starting at or after 'left'
        for (int right = n - 1; right > -1; right--) {
            sum += arr[right];
            while (sum > target) {
                sum -= arr[left];
                left -= 1;
            }
            if (sum == target) {
                best = min(best, abs(left - right + 1));
            }
            suffix[right] = best;
        }
 
        int ans = INF;
        for (int i = 0; i < n - 1; i++) {
            if (prefix[i] != INF && suffix[i + 1] != INF) {
                ans = min(ans, prefix[i] + suffix[i + 1]);
            }
        }
 
        return ans == INF ? -1 : ans;
    }
};