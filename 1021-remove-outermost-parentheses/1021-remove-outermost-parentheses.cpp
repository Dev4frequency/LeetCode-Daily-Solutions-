class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        int left = 0;
        int open = 0;
        string ans = "";

        for (int i = 0; i < n; i++) {

            if (s[i] == '(')
                open++;
            else
                open--;
            if (open == 0) {
                ans += s.substr(left + 1, i - left - 1);
                left = i + 1;
            }
        }

        return ans;
    }
};