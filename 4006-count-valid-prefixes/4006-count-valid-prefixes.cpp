class Solution {
public:
    int countValidPrefixes(string s) {
        int c1=0, c0 = 0, valid = 0;

        for(int i = 0; i<s.length(); i++)
        {
            if(s[i] == '0') c0++;
            else c1++;

            if(abs(c0 - c1) == 1 || c0 == c1) valid++;
        }

        return valid;
    }
};