class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int r=grid.size();
        int c=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(r,vector<int>(c,0));
        int maxarea=0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){

                if(grid[i][j]==1&&vis[i][j]==0){
                    int area=0;
                    vis[i][j]=1;
                    q.push({i,j});

                    int drow[4]={-1,0,1,0};
                    int dcol[4]={0,1,0,-1};

                    while(!q.empty()){
                        auto it=q.front();q.pop();
                        int r2=it.first;
                        int c2=it.second;
                        area++;

                        for(int i=0;i<4;i++){
                            int nrow=r2+drow[i];
                            int ncol=c2+dcol[i];
                            
                            if(nrow>=0&&ncol>=0&&nrow<r&&ncol<c&&
                            grid[nrow][ncol]==1&&!vis[nrow][ncol]){
                                vis[nrow][ncol]=1;
                                q.push({nrow,ncol});
                            }
                        }
                    }
                    maxarea=max(maxarea,area);
                }
            }
        }
        return maxarea;
    }
};