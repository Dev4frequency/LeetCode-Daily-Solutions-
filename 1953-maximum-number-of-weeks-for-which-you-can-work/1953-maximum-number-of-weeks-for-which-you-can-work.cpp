class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
       
        long long total =0;
        int maxM = 0;
        for(int x:milestones)
        {
        total+=x;
        maxM = max(maxM,x);
        }
        long long rest = total- maxM;
        long long ans = min(total , 2*rest+1);
        return ans;
    }
};