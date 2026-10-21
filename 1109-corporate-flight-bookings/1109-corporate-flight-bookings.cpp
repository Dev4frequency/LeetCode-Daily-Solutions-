class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n);
        for (auto& book : bookings) {
            int first = book[0] - 1;
            int last = book[1] - 1;
            int seat = book[2];

            ans[first] += seat;
            if (last + 1 < n) ans[last + 1] -= seat;
        }

        for (int i = 1; i < n; i++) ans[i] += ans[i - 1];
        return ans;
    }
};