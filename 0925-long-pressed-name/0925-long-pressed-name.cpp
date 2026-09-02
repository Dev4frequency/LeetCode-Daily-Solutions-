class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n = name.size();
        int j = 0;
        if(j < n && name.size() > typed.size()) return false;
        for(int i = 0; i < typed.size(); i++){
            if(typed[i] == name[j]){
                j++;
            }else if( i > 0 && typed[i] == typed[i - 1]){
                continue;
            }else{
                return false;
            }
        }
        return j == n;
    }
};