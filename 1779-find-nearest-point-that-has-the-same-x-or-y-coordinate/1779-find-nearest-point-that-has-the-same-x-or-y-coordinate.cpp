class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans = -1;
        int smallest_dist = INT_MAX;
        
        for(int i = 0; i<points.size(); i++){
            if(points[i][0] == x or points[i][1] == y){
                if(abs(x - points[i][0]) + abs(y - points[i][1]) < smallest_dist){
                    ans = i;
                    smallest_dist = abs(x - points[i][0]) + abs(y - points[i][1]);
                }
            }
        }
        
        return ans;
    }
};