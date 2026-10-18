class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string>digfiles;
        vector<pair<string,string>>logfiles;
        int n=logs.size();
        for(int i=0;i<n;i++){
            string s=logs[i];
            int pos=s.find(' ');
            string id=s.substr(0,pos),content=s.substr(pos+1);
            if(isdigit(content[0])){
                digfiles.push_back(s);
            }else{
                logfiles.push_back({content,id});
            }
        }
        sort(logfiles.begin(),logfiles.end());
        vector<string>ans;
        for(auto &[content,id]:logfiles){
            string res=id+' '+content;
            ans.push_back(res);
        }
        for(string s:digfiles){
            ans.push_back(s);
        }
        return ans;
    }
};