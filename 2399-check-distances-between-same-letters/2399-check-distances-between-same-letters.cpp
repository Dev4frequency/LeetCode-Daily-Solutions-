class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<char,int>check;
        vector<int>ans;
        for(int i = 0; i < s.size()-1; i++){
            for(int j = i + 1; j < s.size(); j++){
                if(s[i] == s[j]){
                    check[s[i]] = j - i - 1;
                    break;
                }
            }
        } 
        
        for(auto& it : check){
            if(distance[int(it.first - 'a')] != it.second){
                return false;
            }
        }
        
        return true;
    }
};