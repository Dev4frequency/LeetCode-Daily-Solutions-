class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<vector<int>>ans;
        int i = 0,j = 0;
        int n = series1.size(),m = series2.size();

        while(i<n || j<m)
            {
                int curTime;

                if(i<n && j<m )
                {
                    curTime = min(series1[i][0],series2[j][0]);
                }
                else if(i<n)
                {
                    curTime = series1[i][0];
                }
                else
                {
                    curTime = series2[j][0];
                }

                int val1 = (i<n) ? series1[i][1] : 0;
                int val2 = (j<m) ? series2[j][1] : 0;

                ans.push_back({curTime,val1+val2});

                if(i<n && series1[i][0]==curTime) i++;
                if(j<m && series2[j][0]==curTime) j++;
            }

        return ans;
    }
};