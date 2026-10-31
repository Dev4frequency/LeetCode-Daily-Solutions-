class Solution {
public:
	int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig)
	{
		int m;
		m=artifacts.size();
		vector<int> flag(m,0); 
		vector<vector<int>> grid(1000,vector<int>(1000,INT_MAX));
		for(int i=0;i<m;i++)
		{
			int sr,er,sc,ec;
			sr=artifacts[i][0];
			er=artifacts[i][2];
			sc=artifacts[i][1];
			ec=artifacts[i][3];
			for(int x=sr;x<=er;x++)
			{
				for(int y=sc;y<=ec;y++)
				{
					if(grid[x][y]==INT_MAX)
					{
						flag[i]++;
						grid[x][y]=i;
					}
				}
			}
		}

		for(auto x:dig)
		{
			if(grid[x[0]][x[1]]!=INT_MAX)
			{
				flag[grid[x[0]][x[1]]]--;
				grid[x[0]][x[1]]=INT_MAX;
			}
		}

		return count(flag.begin(),flag.end(),0);
	}
};