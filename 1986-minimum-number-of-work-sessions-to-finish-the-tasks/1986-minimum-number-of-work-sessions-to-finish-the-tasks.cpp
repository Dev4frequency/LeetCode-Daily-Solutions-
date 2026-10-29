class Solution {
public:
    static int minSessions(vector<int> tasks, const int sessionTime) {
        const int n = size(tasks);
        int h = n;
        int l = 1;
        sort(begin(tasks), end(tasks), greater());
        vector<int> dist(n, 0);

        function<bool(int, int)> isPossible = [&] (int i, int limit) {
            if (i == n)
                return true;
            for (int j = 0; j < limit; ++j) {
                if (dist[j] + tasks[i] <= sessionTime) {
                    dist[j] += tasks[i];
                    if (isPossible(i + 1, limit)) {
                        dist[j] -= tasks[i];
                        return true;
                    }
                    dist[j] -= tasks[i];
                }
                if (!dist[j])
                    break;
            }
            return false;
        };

        while (l < h)
            if (int m = ((h - l) >> 1) + l;
                isPossible(0, m))
                h = m;
            else
                l = m + 1;
        return l;
    }
};