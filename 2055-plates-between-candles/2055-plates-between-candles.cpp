class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> prefix(n, 0), left(n), right(n);

        for (int i = 0; i < n; i++) {
            prefix[i] = (i > 0 ? prefix[i - 1] : 0) + (s[i] == '*');
        }

        int candle = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '|') candle = i;
            left[i] = candle;
        }

        candle = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '|') candle = i;
            right[i] = candle;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = right[q[0]];
            int r = left[q[1]];

            if (l == -1 || r == -1 || l >= r) {
                ans.push_back(0);
            } else {
                ans.push_back(prefix[r] - prefix[l]);
            }
        }

        return ans;
    }
};