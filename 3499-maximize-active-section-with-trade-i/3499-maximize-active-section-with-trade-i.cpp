class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        const int n = s.size();
        int active = 0;
        vector<int> zeros; 
        for (int i = 0; i < n; ) {
            if (s[i] == '1') {
                ++active;
                ++i;
                continue;
            }
             int j = i;
            while (j < n && s[j] == '0') ++j;
            zeros.push_back(j - i);
            i = j;
        }

        int bestMerge = 0;
        for (int k = 1; k < (int)zeros.size(); ++k)
            bestMerge = max(bestMerge, zeros[k - 1] + zeros[k]);

        return active + bestMerge;
    }
};