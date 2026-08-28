class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int res = 0;
        
        for (int house : houses) {
            int left = 0, right = heaters.size() - 1, best = INT_MAX;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (heaters[mid] < house) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
                best = min(best, abs(heaters[mid] - house));
            }
            res = max(res, best);
        }
        
        return res;
    }
};