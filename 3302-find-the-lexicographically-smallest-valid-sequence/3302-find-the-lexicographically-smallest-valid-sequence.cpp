class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> suf(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            suf[i] = suf[i + 1];
            if (suf[i + 1] < m && word1[i] == word2[m - 1 - suf[i + 1]])
                suf[i] = suf[i + 1] + 1;
        }
        vector<int> ans;
        ans.reserve(m);
        int j = 0;
        bool changed = false;
        for (int i = 0; i < n && j < m; ++i) {
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                ++j;
            } else if (!changed && (m - 1 - j) <= suf[i + 1]) {
                ans.push_back(i);
                ++j;
                changed = true;
            }
        }
        if (j == m) return ans;
        return {};
    }
};