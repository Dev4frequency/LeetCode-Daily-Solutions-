class Solution {
public:
    string sortString(string s) {
        int freq[26] = {0};

        for (char c : s) {
            freq[c - 'a']++;
        }

        string ans = "";
        int total = s.size();

        while (ans.size() < total) {
            for (int i = 0; i < 26; i++) {
                if (freq[i] > 0) {
                    ans += (char)(i + 'a');
                    freq[i]--;
                }
            }
            for (int i = 25; i >= 0; i--) {
                if (freq[i] > 0) {
                    ans += (char)(i + 'a');
                    freq[i]--;
                }
            }
        }

        return ans;
    }
};