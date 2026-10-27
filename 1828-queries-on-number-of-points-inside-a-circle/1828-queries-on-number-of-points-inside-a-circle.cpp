class Solution 
{
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries)
    {
        vector<int> res;

        for (auto & q : queries) 
        {
            int cx = q[0], cy = q[1], r = q[2];
            int r2 = r * r;
            int count = 0;

            for (auto & p : points)
            {
                int px = p[0], py = p[1];
                int dx = px - cx, dy = py - cy;
                if (dx * dx + dy * dy <= r2) ++count;
            }

            res.push_back(count);
        }

        return res;
    }
};