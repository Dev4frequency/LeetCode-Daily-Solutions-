class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size ();
        
        vector <vector <int>> dis (n, vector <int> (n, 0));
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++)
            {
                int dist = distinct (points, i, j);
                dis [i][j] = dist;
                dis [j][i] = dist;
            }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            vector <int>& len = dis[i];
            sort (len.begin (), len.end ());
            int last = len [0], count = 1;
            for (int j = 1; j < len.size (); j++)
            {
                if (len [j] == last)
                    count++;
                else
                {
                    res += count * (count - 1);
                    count = 1;
                    last = len [j];
                }
            }
            res += count * (count - 1);
        }
        return res;
    }
    int distinct (vector<vector<int>>& points, int i, int j)
    {
        vector<int>& a = points[i];
        vector<int>& b = points[j];
        return (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]);
    }
};