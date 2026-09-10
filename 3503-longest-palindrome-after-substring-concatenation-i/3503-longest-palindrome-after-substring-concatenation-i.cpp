class Solution {
public:
    bool isPalindrome(string str){
        int n=str.length();
        int l=0,r=n-1;
        while(l<r){
            if(str[l]!=str[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    int longestPalindrome(string s, string t) {
        int n=s.length(),m=t.length(),maxPalindrome=1;
        string subStr;
        set<string>sts;
        set<string>stt;
        sts.insert("");
        stt.insert("");
        for(int i=0;i<n;i++){
            subStr="";
            for(int j=i;j<n;j++){
                subStr+=s[j];
                sts.insert(subStr);
            }
        }
        for(int i=0;i<m;i++){
            subStr="";
            for(int j=i;j<m;j++){
                subStr+=t[j];
                stt.insert(subStr);
            }
        }
        for(auto x:sts){
            int xLen=x.length();
            for(auto y:stt){
                int yLen=y.length();
                if(isPalindrome(x+y)) maxPalindrome=max(maxPalindrome,xLen+yLen);
            }
        }
        return maxPalindrome;
    }
};