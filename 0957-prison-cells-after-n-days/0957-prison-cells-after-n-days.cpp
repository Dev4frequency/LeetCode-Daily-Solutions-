class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<int> ans(8);
        for(int i=0;i<=(n-1)%14;i++){
            ans[0]=ans[7]=0;
            for(int i=1;i<7;i++){
                if(cells[i-1]==cells[i+1])
                ans[i]=1;
                else
                ans[i]=0;
            }
            cells=ans;
        }
        return ans;
    }
};