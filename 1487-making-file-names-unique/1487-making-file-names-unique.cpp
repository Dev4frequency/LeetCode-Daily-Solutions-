class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> mp;
        vector<string> result;
        for (const string& name : names) {
            string newName = name;
            if (mp.find(name) != mp.end()) {
                int k = mp[name];
                while (mp.count(name + "(" + to_string(k) + ")")) ++k;
                newName = name + "(" + to_string(k) + ")";
                mp[name] = k + 1;
            }
            mp[newName] = 1;
            result.push_back(newName);
        }
        return result;
    }
};