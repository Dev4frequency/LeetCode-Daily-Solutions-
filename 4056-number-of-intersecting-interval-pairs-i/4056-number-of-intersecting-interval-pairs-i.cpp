class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int maxCoord = 100;

        vector<int> startFreq(maxCoord + 2, 0);

        for (const auto& interval : intervals) {
            startFreq[interval[0]]++;
        }

        vector<int> prefix(maxCoord + 2, 0);
        prefix[0] = startFreq[0];
        for (int i = 1; i <= maxCoord + 1; ++i) {
            prefix[i] = prefix[i - 1] + startFreq[i];
        }

        long long nonIntersectingPairs = 0;

        for (const auto& interval : intervals) {
            int end = interval[1];
            if (end < maxCoord) {
                int intervalsStartingAfter = n - prefix[end];
                nonIntersectingPairs += intervalsStartingAfter;
            }
        }

        long long totalPairs = (long long)n * (n - 1) / 2;

        return (int)(totalPairs - nonIntersectingPairs);
    }
};