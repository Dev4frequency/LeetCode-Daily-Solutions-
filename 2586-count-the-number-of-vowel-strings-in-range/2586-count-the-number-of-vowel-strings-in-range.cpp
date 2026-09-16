class Solution {
public:
    bool isvowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u')
            return true;
        return false;
    }
    int vowelStrings(vector<string>& words, int left, int right) {
        int count = 0;
        for (int i = left; i <= right; i++) {
            string w = words[i];
            if (isvowel(w.front()) && isvowel(w.back()))
                count++;
        }
        return count;
    }
};