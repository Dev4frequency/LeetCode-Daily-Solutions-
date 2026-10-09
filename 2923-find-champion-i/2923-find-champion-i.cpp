class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int max=0,winner=0;
        for(int i=0;i<grid.size();i++)
        {
            max+=grid[0][i];
        }
        for(int i=1;i<grid.size();i++)
        {
            int sum=0;
            for(int j=0;j<grid.size();j++)
            {
                sum+=grid[i][j];
            }
            if(sum>max)
            {
                max=sum;
                winner=i;
            }
        }
        return winner;
    }
};