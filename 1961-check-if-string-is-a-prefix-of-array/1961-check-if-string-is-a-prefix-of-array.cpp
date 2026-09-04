class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string emp="";
        for(int i=0;i<words.size();i++){
            emp+=words[i];
            if(emp==s) return true;
        }
        return false;

    }
};