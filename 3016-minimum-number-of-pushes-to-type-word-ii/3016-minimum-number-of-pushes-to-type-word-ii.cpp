class Solution {
public:
    int minimumPushes(string word) {
        vector<int> cnt(26, 0);
        for (char c : word) cnt[c - 'a']++;
        sort(cnt.rbegin(), cnt.rend());
        int total = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 0) break;
            total += (i / 8 + 1) * cnt[i];
        }
        return total;
    }
};