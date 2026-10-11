class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int start = events[0][0], end = events[0][1];
        vector<pair<int, int>> v;
        v.push_back({start, end});
        int n = events.size();
        for (int i = 1; i < n; i++) {
            int diff = events[i][1] - events[i - 1][1];
            v.push_back({events[i][0], diff});
        }
        auto maxElement = std::max_element(v.begin(), v.end(),
            [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                return (a.second < b.second) || (a.second == b.second && a.first > b.first);
            });
        return maxElement->first;
    }
};