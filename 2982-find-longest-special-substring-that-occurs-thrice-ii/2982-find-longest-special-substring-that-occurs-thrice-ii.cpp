class Solution {
public:
    int maximumLength(string s) {
        int n=s.length();

        vector<vector<int>>f(26, vector<int>(n+1, 0));
        char prev=' ';
        int len=0;

        for(int i=0; i<n; i++){
            if(prev==' ' || prev!=s[i]){
                prev=s[i];
                len=1;
            }else{
                len+=1;
            }
            f[s[i]-'a'][len]+=1;
        }

        int maxi=-1;

        for(int i=0; i<26; i++){
            int sum=0;
            for(int j=n; j>=0; j--){
                sum+=f[i][j];
                if(sum>=3){
                    maxi=max(maxi, j);
                    break;
                }
            }
        }

        return maxi;
        
    }
};