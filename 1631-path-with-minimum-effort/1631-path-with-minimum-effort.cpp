class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& path) {
        int m=path.size(),n=path[0].size();
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        pq.push({0,0,0});
        vector<vector<int>>dis(m,vector<int>(n,INT_MAX));
        vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        dis[0][0]=0;
        while(pq.size()>0){
            auto [effort,r,c]=pq.top();
            pq.pop();
            if(effort>dis[r][c]) continue;
            for(auto &p:dir){
                int nr=r+p.first,nc=c+p.second;
                if(nr<0 || nr>=m || nc<0 || nc>=n) continue;
                int edge=abs(path[r][c]-path[nr][nc]);
                int neweffort=max(effort,edge);
                if(neweffort<dis[nr][nc]){
                    dis[nr][nc]=neweffort;
                    pq.push({neweffort,nr,nc});
                }
            }
        }
        return dis[m-1][n-1];
    }
};