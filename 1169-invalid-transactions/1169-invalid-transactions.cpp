class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n = transactions.size();
        vector<string> name(n), city(n);
        vector<int> amt(n), time(n);
        vector<string> ans;
        for (int i = 0; i < n; i++) {
            vector<string> part;
            string temp = "";
            string s = transactions[i];

            for (char i : s) {
                if (i == ',') {
                    part.push_back(temp);
                    temp = "";
                } else {
                    temp += i;
                }
            }
            part.push_back(temp);
            name[i] = part[0];
            time[i] = stoi(part[1]);
            amt[i] = stoi(part[2]);
            city[i] = part[3];
        }
        for (int i = 0; i < n; i++) {
            bool invalid = false;
            if (amt[i] > 1000) {
                invalid = true;
            }
                for (int j = 0; j < n; j++) {
                    if (i == j)
                        continue;
                    if (name[i] == name[j] && city[i] != city[j] &&
                        abs(time[i] - time[j]) <= 60) {
                        invalid = true;
                    }
                }
            
            if (invalid) {
                ans.push_back(transactions[i]);
            }
        }
            return ans;
        }
    };