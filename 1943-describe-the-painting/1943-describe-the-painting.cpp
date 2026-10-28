class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<long long, long long> diff;
        set<long long> points;

        for (const vector<int>& seg : segments) {
            long long l = seg[0];
            long long r = seg[1];
            long long c = seg[2];

            diff[l] += c;
            diff[r] -= c;
            points.insert(l);
            points.insert(r);
        }
        vector<long long> vpts(points.begin(), points.end());

        vector<vector<long long>> result;
        long long currentColor = diff[vpts[0]];

        for (int i = 1; i < (int)vpts.size(); i++) {
            if (currentColor > 0) {
                result.push_back({vpts[i - 1], vpts[i], currentColor});
            }
            currentColor += diff[vpts[i]];
        }

        return result;
    }
};