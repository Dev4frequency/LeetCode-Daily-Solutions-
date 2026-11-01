class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        unordered_set<string> points;
        for (auto& circle : circles) {
            int x = circle[0], y = circle[1], r = circle[2];
            for (int dx = -r; dx <= r; ++dx) {
                for (int dy = -r; dy <= r; ++dy) {
                    if (dx * dx + dy * dy <= r * r) {
                        points.insert(to_string(x + dx) + "," + to_string(y + dy));
                    }
                }
            }
        }
        return points.size();
    }
};