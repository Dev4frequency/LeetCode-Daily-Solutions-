class Solution {
public:
    typedef pair<int, pair<int,int>> p;

    int minCostConnectPoints(vector<vector<int>>& points) {

        priority_queue<p, vector<p>, greater<p>> pq;

        int start = points[0][0];
        int end = points[0][1];
        pq.push({0, {start, end}});

        set<pair<int,int>> vis;

        int sum = 0;

        while (!pq.empty())
        {
            int cost = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;

            pq.pop();

            if (vis.count({x, y}))
                continue;

            sum += cost;
            vis.insert({x, y});

            for (int i = 0; i < points.size(); i++)
            {
                int c_x = points[i][0];
                int c_y = points[i][1];

                if ((c_x == x && c_y == y) ||
                    vis.count({c_x, c_y}))
                    continue;

                int dist = abs(x - c_x) + abs(y - c_y);

                pq.push({dist, {c_x, c_y}});
            }
        }

        return sum;
    }
};