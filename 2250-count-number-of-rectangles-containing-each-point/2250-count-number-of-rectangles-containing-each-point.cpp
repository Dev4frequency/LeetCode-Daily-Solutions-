class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        map<int, vector<int>> heightToLengths;
        for (const auto& rect : rectangles) {
            int len = rect[0], ht = rect[1];
            heightToLengths[ht].push_back(len);
        }

        for (auto& [ht, lengths] : heightToLengths) {
            sort(lengths.begin(), lengths.end());
        }

        vector<int> result;
        for (const auto& point : points) {
            int x = point[0], y = point[1];
            int count = 0;
            for (const auto& [ht, lengths] : heightToLengths) {
                if (ht < y) continue;
                auto it = lower_bound(lengths.begin(), lengths.end(), x);
                count += (lengths.end() - it);
            }
            result.push_back(count);
        }
        return result;
    }
};