
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        int x=1;
        int y=1000;
        
        
        vector<vector<int>> ans;
        while(x>=1 && y>=1)
        {
            
            if(customfunction.f(x,y)==z)
            {
                ans.push_back({x,y});
                x++;
            }
            else if(customfunction.f(x,y)>z)
                y--;
        
            else
                x++;
            
        }
        return ans;
    }
};