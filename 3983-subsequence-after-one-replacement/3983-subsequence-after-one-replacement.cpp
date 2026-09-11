class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n=s.size(),m=t.size();
        vector<int>first(n,m),last(n,-1);
        int j=0;
        for(int i=0;i<n&& j<m;i++){
            while(j<m && t[j]!=s[i]) j++;
            if(j<m){
                first[i]=j;
                j++;
            }
        }
        j=m-1;
        for(int i=n-1;i>=0 && j>=0;i--){
            while(j>=0 && t[j]!=s[i]) j--;
            if(j>=0){
                last[i]=j;
                j--;
            }
        }
        for(int i=0;i<n;i++){
            int left=(i==0)?-1:first[i-1];
            int right=(i==n-1)?m:last[i+1];
            if(right-left>=2) return true;
        }
        return false;
    }
};