class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
       const int N = s.size();

        const auto makeKMPTable = [&](const string_view& needle) -> vector<int> {
            const int NS = needle.size();
            vector<int> prefix { 0 }; prefix.reserve(NS+1);
            int p = 0;
            for (int i = 1; i < NS; ++i) {
                while (p && needle[p] != needle[i]) p = prefix[p-1];
                p += needle[p] == needle[i];
                prefix.push_back(p);
            }
            return prefix;
        };

        const auto findIndices = [&](const string_view& needle) -> vector<int> {
            const int NS = needle.size();
            const auto prefix = makeKMPTable(needle);
            int p = 0;
            vector<int> idxs;
            for (int i = 0; i < N; ++i) {
                while (p && needle[p] != s[i]) p = prefix[p-1];
                p += needle[p] == s[i];
                if (p == NS) {
                    idxs.push_back(i-NS+1);
                    p = prefix.back();
                }
            }
            return idxs;
        };

        const auto bIdxs = findIndices(b);
        const int B = bIdxs.size();
        const auto aIdxs = findIndices(a);
        int bb = 0;
        vector<int> ans;
        for (const auto& i : aIdxs) {
            while (bb < B && bIdxs[bb] < i-k) ++bb;
            if (bb < B && abs(bIdxs[bb]-i) <= k) ans.push_back(i);
        }
        return ans;
    }
};