class Solution {
public:
    string makeSmallestPalindrome(string s) {
      int n = s.length();
      for (int left = 0, right = n - 1; left <= right; ++left, --right) {
        if (s[left] != s[right]) {
            char smallerChar = std::min(s[left], s[right]);
            s[left] = smallerChar;
            s[right] = smallerChar;
        }
    }
    return s;
}
};