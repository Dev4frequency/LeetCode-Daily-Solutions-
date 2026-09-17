class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>> colorCounts(n, vector<int>(11, 0));

        for (const auto& p : pick) {
            int player = p[0], color = p[1];
            colorCounts[player][color]++;
        }
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int val : colorCounts[i]) {
                if (val > i) {
                    count++;
                    break;
                }
            }
        }

        return count;
    }
};