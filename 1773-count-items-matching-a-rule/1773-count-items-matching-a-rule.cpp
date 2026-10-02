class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int size = items.size();
        int result = 0;
        if(ruleKey == "type"){
            for(int i = 0; i < size; i++){
                if(items[i][0] == ruleValue)
                    result++;
            }
        }
        else if(ruleKey == "color"){
            for(int i = 0; i < size; i++){
                if(items[i][1] == ruleValue)
                    result++;
            }
        }
        else{
            for(int i = 0; i < size; i ++){
                if(items[i][2] == ruleValue)
                    result++;
            }
        }
        return result;
    }
};