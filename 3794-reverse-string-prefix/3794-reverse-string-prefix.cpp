class Solution {
public:
    string reversePrefix(string s, int k) {
        int n=k-1,i=0;
        while(i<=n){
            swap(s[i],s[n]);
            i++;
            n--;
        }
        return s;
    }
};