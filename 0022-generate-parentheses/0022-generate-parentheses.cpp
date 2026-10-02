class Solution {
public:
   void Parenthesis(int start,int end,int n,string str,vector<string>&s){
       
       if(str.size()==2*n){
           s.push_back(str);
           return;
       }else{
           if(start<n){
               Parenthesis(start+1,end,n,str+'(',s);
           }
           if(end<start){
               Parenthesis(start,end+1,n,str+')',s);
           }
       }

    }
    vector<string> generateParenthesis(int n) {
      string str="";
      vector<string>s;
      Parenthesis(0,0,n,str,s);
      return s;
    }
};