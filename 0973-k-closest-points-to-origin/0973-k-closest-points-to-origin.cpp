class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;
        for(int i=0; i<points.size(); i++){
            int x = points[i][0];
            int y = points[i][1];
            int d = x*x + y*y;
            pair<int,int> curr={d,i};
            if(pq.size()<k){
                pq.push(curr);
                continue;
            }
            if(curr.first<pq.top().first){
                pq.pop();
                pq.push(curr);
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            int j=pq.top().second;
            ans.push_back(points[j]);
            pq.pop();
        }
        return ans;
    }
};