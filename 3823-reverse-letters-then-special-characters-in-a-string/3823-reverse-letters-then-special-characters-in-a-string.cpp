class Solution {
public:
    string reverseByType(string s) {
       string letters = "";
        string special = "";

        
        for (char c : s) {
            if (islower(c))
                letters += c;
            else
                special += c;
        }

        reverse(letters.begin(), letters.end());
        reverse(special.begin(), special.end());

       
        int i = 0, j = 0;

        for (int k = 0; k < s.length(); k++) {
            if (islower(s[k])) {
                s[k] = letters[i++];
            } else {
                s[k] = special[j++];
            }
        }

        return s;
    }
};