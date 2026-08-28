class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        auto isSubsequence = [](const string& a, const string& b) {
            int i = 0;
            for (char c : b) {
                if (i < a.size() && a[i] == c) ++i;
            }
            return i == a.size();
        };

        int n = strs.size(), result = -1;
        for (int i = 0; i < n; ++i) {
            bool unique = true;
            for (int j = 0; j < n; ++j) {
                if (i != j && isSubsequence(strs[i], strs[j])) {
                    unique = false;
                    break;
                }
            }
            if (unique) result = max(result, (int)strs[i].size());
        }
        return result;
    }
};