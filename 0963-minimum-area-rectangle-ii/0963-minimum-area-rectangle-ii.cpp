class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
	int n = points.size();
	
	set<pair<int, int>> exists;
	for (auto p : points)
		exists.insert({p[0], p[1]});

	double ans = INT_MAX;
	
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			for (int k=j+1; k<n; k++) {
				
				int x1 = points[i][0], y1 = points[i][1], x2 = points[j][0], y2 = points[j][1], x3 = points[k][0], y3 = points[k][1];
                if ((y2-y1) * (y3-y1) + (x2-x1) * (x3 - x1) == 0) {
					
					int x4 = x2 + x3 - x1;
					int y4 = y2 + y3 - y1;
					
					if (exists.find({x4, y4}) != exists.end()) {
						double area = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)) * sqrt((x3-x1)*(x3-x1) + (y3-y1)*(y3-y1));

						if (area < ans)
							ans = area;
					}
				}
			}
		}
	}
	
	if (ans == INT_MAX)
		return 0;
	return ans;
}

};