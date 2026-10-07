class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        vector<priority_queue<int>> heaps;
        for (auto& row : grid) {
            priority_queue<int> pq(row.begin(), row.end());
            heaps.push_back(pq);
        }

        int r = grid.size();
        int c = grid[0].size();
        int ans = 0;

        for (int i = 0; i < c; ++i) {
            int max_val = 0;
            for (int j = 0; j < r; ++j) {
                if (!heaps[j].empty()) {
                    int row_max = heaps[j].top();
                    heaps[j].pop();
                    max_val = max(max_val, row_max);
                }
            }
            ans += max_val;
        }

        return ans;
    }
};