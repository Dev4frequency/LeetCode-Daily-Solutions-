class Solution {
public:
    unordered_map<string, int> memo;
    string encode(vector<int>& needs) {
        string key = "";
        for (int x : needs) key += to_string(x) + ",";
        return key;
    }

    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int> needs) {
        string key = encode(needs);
        if (memo.count(key)) return memo[key];

        int n = price.size();
        int cost = 0;
        for (int i = 0; i < n; i++) 
            cost += needs[i] * price[i];
        for (auto &offer : special) {
            bool valid = true;
            vector<int> newNeeds(needs);

            for (int i = 0; i < n; i++) {
                if (offer[i] > newNeeds[i]) {  
                    valid = false; 
                    break;
                }
                newNeeds[i] -= offer[i];
            }

            if (valid) {
                cost = min(cost, offer[n] + dfs(price, special, newNeeds));
            }
        }

        return memo[key] = cost;
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        memo.clear();
        return dfs(price, special, needs);
    }
};