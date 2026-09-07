class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string ans;
        int xA = 0;
        int yA = 0;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == x) ++xA;
            else if(s[i] == y) ++yA;
            else ans += s[i];
        }
        ans = string(yA, y) + ans + string(xA, x);
        return ans;
    }
};