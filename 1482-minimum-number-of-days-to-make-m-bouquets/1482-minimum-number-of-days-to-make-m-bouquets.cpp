class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (1LL * m * k > bloomDay.size()) {
            return -1;
        }

        int mini = INT_MAX, maxi = INT_MIN;

        for (int x : bloomDay) {
            mini = min(mini, x);
            maxi = max(maxi, x);
        }

        while (mini <= maxi) {
            int mid = mini + (maxi - mini) / 2;

            int count = 0, bouquets = 0;

            for (int x : bloomDay) {
                if (x <= mid) {
                    count++;

                    if (count == k) {
                        bouquets++;
                        count = 0;
                    }
                } else {
                    count = 0;
                }
            }

            if (bouquets >= m) {
                maxi = mid - 1;
            } else {
                mini = mid + 1;
            }
        }

        return mini;
    }
};