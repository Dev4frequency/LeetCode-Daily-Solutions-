class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int a=0,b=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                a++;
            }else{
                b++;
            }
        }

        vector<bool>ret(strs.size());
        for(int i=0;i<strs.size();i++){
            int ta=0,tb=0;
            for(int j=0;j<s.length();j++){
                if(strs[i][j]=='0'){
                    ta++;
                }else if(strs[i][j]=='1'){
                    tb++;
                }
            }
            if(ta>a || tb>b){
                ret[i]=false;
                continue;
            }

            int difa=a-ta;
            int difb=b-tb;

            string tem=strs[i];
            for(int i=0;i<s.length();i++){
                if(tem[i]=='?'){
                    if(difa>0){
                        tem[i]='0';
                        difa--;
                    }else{
                        tem[i]='1';
                    }
                }
            }

            int cnt1=0,cnt2=0;
            bool f=false;
            for(int j=0;j<s.length();j++){
                if(s[j]=='1'){
                    cnt1++;
                }
                if(tem[j]=='1'){
                    cnt2++;
                }
                if(cnt2>cnt1){
                    ret[i]=false;
                    f=true;
                    continue;
                }
            }
            if(!f){
                ret[i]=true;
            }
        }
        return ret;
    }
};