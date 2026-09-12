class Solution {
public:

    void generate(vector<int>& arr,
                  int start,
                  int end,
                  vector<vector<int>>& sums) {

        int len = end - start;

        for (int mask = 0; mask < (1 << len); mask++) {

            int sum = 0;
            int cnt = 0;

            for (int j = 0; j < len; j++) {

                if (mask & (1 << j)) {
                    sum += arr[start + j];
                    cnt++;
                }
            }

            sums[cnt].push_back(sum);
        }
    }

    int minimumDifference(vector<int>& arr) {

        int totalElements = arr.size();
        int n = totalElements / 2;

        int totalSum = 0;

        for (int x : arr)
            totalSum += x;

        vector<vector<int>> left(n + 1);
        vector<vector<int>> right(n + 1);
        generate(arr, 0, n, left);
        generate(arr, n, totalElements, right);
        for (int i = 0; i <= n; i++) {
            sort(right[i].begin(), right[i].end());
        }

        int ans = INT_MAX;
        for (int k = 0; k <= n; k++) {
            int need = n - k;
            for (int leftSum : left[k]) {

                double target = (double)totalSum / 2 - leftSum;

                auto& vec = right[need];

                auto it = lower_bound(vec.begin(), vec.end(), target);

                if (it != vec.end()) {

                    int selectedSum = leftSum + *it;

                    int diff = abs(
                        totalSum - 2 * selectedSum
                    );

                    ans = min(ans, diff);
                }
                if (it != vec.begin()) {

                    --it;

                    int selectedSum = leftSum + *it;

                    int diff = abs(
                        totalSum - 2 * selectedSum
                    );

                    ans = min(ans, diff);
                }
            }
        }

        return ans;
    }
};