class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        bool bl=false;
        vector<string> res;
        string s;
        for(auto x : source){
            
            for(auto i=0; i < x.size(); i++){
                if(bl==false){
                    if(x[i]=='/'&& i < x.size()-1 && x[i+1]=='/')
                        break;
                    if(x[i]=='/'&& i < x.size()-1 && x[i+1]=='*')
                    {
                        bl=true;
                        i++;
                    }else
                        s+=x[i];
                }else{      
                    if(x[i]=='*' && i<x.size()-1 &&x[i+1]=='/')
                    {
                        bl=false;
                        i++;
                    }
                }
            }
            if(!bl)
                if(!s.empty()){
                    res.push_back(s);
                    s="";
                }
        }
        return res;
    }
};