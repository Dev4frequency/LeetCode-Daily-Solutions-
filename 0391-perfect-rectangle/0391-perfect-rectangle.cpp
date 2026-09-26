class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_map<string, int> edgeCount;
        long long minX = LLONG_MAX, minY = LLONG_MAX, maxX = LLONG_MIN, maxY = LLONG_MIN;
        long long totalArea = 0;
        
        for (auto& rect : rectangles) {
            long long x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];
            totalArea += (x2 - x1) * (y2 - y1);
            minX = min(minX, x1);
            minY = min(minY, y1);
            maxX = max(maxX, x2);
            maxY = max(maxY, y2);
            
            edgeCount[to_string(x1) + "," + to_string(y1)]++;
            edgeCount[to_string(x1) + "," + to_string(y2)]++;
            edgeCount[to_string(x2) + "," + to_string(y1)]++;
            edgeCount[to_string(x2) + "," + to_string(y2)]++;
        }
        if (totalArea != (maxX - minX) * (maxY - minY)) {
            return false;
        }
        vector<string> corners = {
            to_string(minX) + "," + to_string(minY),
            to_string(minX) + "," + to_string(maxY),
            to_string(maxX) + "," + to_string(minY),
            to_string(maxX) + "," + to_string(maxY)
        };
        
        for (const auto& corner : corners) {
            if (edgeCount[corner] != 1) {
                return false;
            }
        }
        for (const auto& [edge, count] : edgeCount) {
            if (count % 2 != 0 && find(corners.begin(), corners.end(), edge) == corners.end()) {
                return false;
            }
        }
        
        return true;
    }
};