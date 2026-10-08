class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        string c;
        vector<string>ans;
        int n=words.size();
       
        int i=0;
        int j=0;
        for(int i=0;i<n;i++){
            int m=words[i].size();
            for(int j=0;j<m;j++){
                if(words[i][j]==separator){
                    if(c.size()>0){
                    ans.push_back(c);
                    c.clear();
                    
                    }
                }
                else c+=words[i][j];
            }
            if(c.size()>0){
                ans.push_back(c);
            }
            c.clear();

        }
        return ans;
    }
};