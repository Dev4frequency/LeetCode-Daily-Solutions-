class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        unordered_set<char> visited;
        int ans = 0;
        for (auto& it : freq) {
            char c = it.first;
            if (visited.count(c))
                continue;
            char m;
            if (isalpha(c)) {
                m = 'z' - (c - 'a');
            } else {
                m = '9' - (c - '0');
            }
            int f1 = freq[c];
            int f2 = freq.count(m) ? freq[m] : 0;

            ans += abs(f1 - f2);
            visited.insert(c);
            visited.insert(m);
        }
        return ans;
    }
};