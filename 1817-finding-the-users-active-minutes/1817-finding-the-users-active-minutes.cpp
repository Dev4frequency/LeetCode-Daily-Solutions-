class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int,unordered_set<int>>m;
        for(int i=0 ; i<logs.size() ; i++)
        {
            m[logs[i][0]].insert(logs[i][1]);
        }
        vector<int>UAM;
        
        for(auto it : m)
        {
            UAM.push_back(it.second.size());
        }
        vector<int>result(k,0);
        for(int i = 0; i < UAM.size(); i++) {
        int uam_count = UAM[i];
        if(uam_count <= k) { 
        result[uam_count - 1]++;
        }
    }
    return result;

    }
};