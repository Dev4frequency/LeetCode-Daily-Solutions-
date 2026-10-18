class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, set<int>> pointMap;
        int minArea = numeric_limits<int>::max();
        for (const auto& point : points) {
            pointMap[point[0]].insert(point[1]);
        }
        for (size_t i = 0; i < points.size(); i++) {
            for (size_t j = i + 1; j < points.size(); j++) {
                if (points[i][0] != points[j][0] && points[i][1] != points[j][1]) {
                    if (pointMap[points[i][0]].count(points[j][1]) &&
                        pointMap[points[j][0]].count(points[i][1])) {
                        int area = abs(points[i][0] - points[j][0]) * abs(points[i][1] - points[j][1]);
                        minArea = min(minArea, area);
                    }
                }
            }
        }
        return minArea == numeric_limits<int>::max() ? 0 : minArea;
    }
};