class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        unordered_map<string, unordered_map<string, int>> order;
        unordered_set<string> tablesSet, itemsSet;

        for (auto &v : orders) {
            string table = v[1];
            string item  = v[2];
            order[table][item]++;
            tablesSet.insert(table);
            itemsSet.insert(item);
        }

        vector<string> tables(tablesSet.begin(), tablesSet.end());
        vector<string> items(itemsSet.begin(), itemsSet.end());

        sort(tables.begin(), tables.end(), [](const string &a, const string &b){
            return stoi(a) < stoi(b);
        });

        sort(items.begin(), items.end());

        vector<vector<string>> ans;

        vector<string> header = {"Table"};
        for (string &item : items)
            header.push_back(item);

        ans.push_back(header);

        for (string &tableNo : tables) {
            vector<string> row = {tableNo};
            for (string &item : items) {
                int cnt = order[tableNo].count(item) ? order[tableNo][item] : 0;
                row.push_back(to_string(cnt));
            }
            ans.push_back(row);
        }

        return ans;
    }
};