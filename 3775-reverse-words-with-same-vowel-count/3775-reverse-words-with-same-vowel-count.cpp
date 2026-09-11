class Solution {
public:
    bool isVow(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        }
        return false;
    }
    string reverseWords(string s) {
        int n = s.length();
        int i = 0;
        int j = 1;
        int first = -1;
        while (j <= n) {
            if (s[j] == ' ' || j == n) {
                int vol = 0;
                for (int p = i; p < j; p++) {
                    if (isVow(s[p])) {
                        vol++;
                    }
                }
                if (first == -1)
                    first = vol;
                else if (vol == first) {
                    reverse(s.begin() + i, s.begin() + j);
                }
                i = j + 1;
            }
            j++;
        }
        return s;
    }
};