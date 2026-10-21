class Solution {
public:
    int comparingCases(int s1, int s2, auto& a1, auto& a2){
        int mx=INT_MIN, mn=INT_MAX, n=a1.size();
        for(int i=0;i<n;i++){
            mx=max(mx, a1[i]+s1*a2[i]+s2*i);
            mn=min(mn, a1[i]+s1*a2[i]+s2*i);
        }
        return (mx-mn);
    }
    int maxAbsValExpr(vector<int>& a1, vector<int>& a2) {
        int ans=0;
        for(int s1 : {-1,1}){
            for(int s2 : {-1, 1}){
                ans=max(comparingCases(s1, s2, a1, a2), ans);
            }
        }
        return ans;
    }
};