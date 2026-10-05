class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        string temp="";
        int  count=0;
        for(int i=0;i<s.size();i++){
            temp+=s[i];
            for(int j=0;j<words.size();j++){
                if(temp==words[j]){
                    count++;
                }
            }

        }
        return count;

        
    }
};