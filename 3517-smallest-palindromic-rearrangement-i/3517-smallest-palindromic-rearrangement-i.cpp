class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        int oddCount = 0;
        char oddChar = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                oddCount++;
                oddChar = 'a' + i;
            }
        }

        if (oddCount > 1) return "";

        string half = "";
        for (int i = 0; i < 26; i++) {
            half += string(freq[i] / 2, 'a' + i);
        }

        string result = half;
        if (oddCount == 1) {
            result += oddChar;
        }

        reverse(half.begin(), half.end());
        result += half;

        return result;
    }
};