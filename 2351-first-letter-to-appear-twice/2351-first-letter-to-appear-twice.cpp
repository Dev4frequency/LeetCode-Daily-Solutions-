class Solution {
public:
    char repeatedCharacter(string s) {
        map<char,int> m;
        for(int y=0;y<s.size();y++)
        {
            m[s[y]]++;
            if(m[s[y]]==2)
                return s[y];
                }
        return -1;  
    }
};