class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size(), time, res=0;
        for(int i=0;i<n;i++) {
            time = dist[i]/speed[i];
            (dist[i] % speed[i]) ? time++ : 1;
            dist[i] = time;
        }

        sort(dist.begin(), dist.end());
        
        int kill = 0;
        while(kill < n) {
            if(kill >= dist[kill]) break;
            kill++;
        }

        return kill;
    }
};