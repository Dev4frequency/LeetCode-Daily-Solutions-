class Solution {
public:
    int firstMatchingIndex(string s) {
        int n = s.length();

        int l =0;
        int r = n-1;

        while(l <= r){
            if(s[l] == s[r]){
                return l;
            }
            else{
                l++;
                r--;
            }
        }

        return -1;

    }
};