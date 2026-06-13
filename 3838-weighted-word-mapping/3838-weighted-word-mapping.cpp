class Solution {
    int modulo = 26;

public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        int n = words.size();

        for(int i = 0; i < n; i++) {
            int wt = 0;

            for(int j = 0; j < words[i].length(); j++) {
                char ch = words[i][j];
                int index = ch - 'a';
                wt += weights[index];
            }

            wt %= 26;
            ans.push_back(alphabet[alphabet.size() - wt - 1]);
        }

        return ans;
    }
};