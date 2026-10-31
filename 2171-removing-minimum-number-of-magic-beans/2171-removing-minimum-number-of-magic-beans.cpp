class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(),beans.end());
        long long total=accumulate(beans.begin(), beans.end(),0LL);
        long long minRemoval=LLONG_MAX;
        for(int i=0;i<beans.size();i++){
            long long t=0;
            t=total-(1LL*beans[i]*(beans.size()-i));
            if(minRemoval>t){
                minRemoval=t;
            }
        }
        return minRemoval;
    }
};