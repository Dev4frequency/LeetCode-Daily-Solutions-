class Solution {
public:
    int minOperations(string s) {
        string p = s;
        int n = s.size();
        sort(p.begin(), p.end());

        if(s.size() < 3) {
            if(p == s) {
                return 0;
            }
            else {
                return -1;
            }
        }

        if(p == s) {
            return 0;
        }

        if(s[0] == p[0] || s[n - 1] == p[n - 1]) {
            return 1;
        }
        else if(s[0] == p[n - 1] && s[n - 1] == p[0]) {
            if(p[n - 1] == p[n - 2] || p[0] == p[1]) {
                return 2;
            }
            return 3;
        }
        else {
            return 2;
        }
    }
};