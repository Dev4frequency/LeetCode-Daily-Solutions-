class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {

        int cnt = 0;
        int start = 0;

        for(auto rung: rungs) {
            if((rung-start)>dist) {
                cnt += (rung-start-1)/dist;
            }
            start = rung;
        }

        return cnt;
        
    }
};