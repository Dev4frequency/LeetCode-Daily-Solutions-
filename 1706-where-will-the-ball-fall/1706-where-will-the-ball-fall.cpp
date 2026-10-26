class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        for(int j=0 ; j<grid[0].size();j++)
        {
            int j1=j ,j2;
            for(int i=0;i<grid.size();i++)
            {
                j2=j1+grid[i][j1];
                if(j2<0 || j2>=grid[0].size() || grid[i][j1]!=grid[i][j2])
                {
                    j1=-1;
                    break;
                }
                j1=j2;
            }
            ans.push_back(j1);
        }
        return ans;
    }
};