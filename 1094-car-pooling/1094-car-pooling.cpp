class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>changes(1001,0);
        for(auto it:trips){
            int numpassangers=it[0];
            int start=it[1];
            int end=it[2];
            changes[start]=changes[start]+numpassangers;
            changes[end]=changes[end]-numpassangers;
        }
        int currentpassangers=0;
        for(int i=0;i<changes.size();i++){
            currentpassangers+=changes[i];
            if(currentpassangers>capacity){
                return false;
            }
        }
        return true;
        
    }
};