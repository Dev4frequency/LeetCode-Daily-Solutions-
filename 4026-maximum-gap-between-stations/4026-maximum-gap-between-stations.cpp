class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size();
        int m = station.size();
        vector<int> l(n),r(n);
        for(int i=0,j=0;i<n;i++){
            while(j<m && station[j] != skill[i])
                j++;
            l[i] = j++;
        }
        for(int i=n-1,j=m-1;i>=0;i--){
            while(j>=0&&station[j]!=skill[i])
                j--;
            r[i] = j--;
        }
        int ans = 0;
        for(int i=1;i<n;i++){
            ans = max(ans,r[i]-l[i-1]);
        }
        return ans;
    }
};