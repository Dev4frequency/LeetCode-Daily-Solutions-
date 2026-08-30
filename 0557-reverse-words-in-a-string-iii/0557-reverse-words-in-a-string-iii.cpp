class Solution {
public:
    string reverseWords(string s) {
        int i=0,j=0;
        while(i<=j && j<s.size())
        {
            if(s[j]==' ')
            {
                reverse(s.begin()+i,s.begin()+j);
                i=j+1;
            }
            else if(j==s.size()-1)
            reverse(s.begin()+i,s.end());
            j++;
        }
        return s;
    }
};