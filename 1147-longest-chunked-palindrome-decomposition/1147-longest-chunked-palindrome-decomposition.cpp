class Solution {
public:
    int longestDecomposition(string text) {
        return helper(text, 0, text.length() - 1);
    }

    int helper(string& text, int left, int right) {
        if (left > right) {
            return 0;
        }
        
        for (int i = 1; i <= (right - left + 1) / 2; ++i) {
            if (text.substr(left, i) == text.substr(right - i + 1, i)) {
                return 2 + helper(text, left + i, right - i);
            }
        }
        
        return 1;
    }
};