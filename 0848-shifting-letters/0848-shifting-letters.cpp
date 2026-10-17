class Solution {
public:
    string shiftingLetters(string s, vector<int>& shift) {

     for(int i=shift.size()-1;i>=0;i--)
     { 
      if (i!=shift.size()-1)  
       shift[i]= (shift[i]+shift[i+1])%26;
     }
     for(int i=0;i<s.size();i++)
     { 
        s[i]= (s[i]-'a' + shift[i])%26 + 'a';
     }
        return s;
    }
};