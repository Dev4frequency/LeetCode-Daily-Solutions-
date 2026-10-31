class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        ios_base::sync_with_stdio(0);
        int ans = 0; vector<int>answ(12,0);
        for(int mask = 0; mask < (1 << 12); mask++){
            int j = 0,s = 0,score = 0;
            while(j < 12){
                if((mask & (1 << j))){
                    s += aliceArrows[j] + 1;
                    score += j;
                }
                j++;
            }
            if(s <= numArrows){
                if(score > ans){
                    ans = score;
                    int last = -1;
                    for(int i = 0; i < 12; i++){
                        answ[i] = 0;
                        if((mask & (1 << i))){
                            last = i;
                            answ[i] = aliceArrows[i] + 1;
                        }
                    }
                    if(s < numArrows){
                        answ[last] += numArrows - s;
                    }
                }
            }
        }
        return answ;
    }
};