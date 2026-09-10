class Solution {
public:
#define all(x) x.begin(), x.end()
    string lexSmallest(string s) {
        string temp1, temp2;
        string res;
        string pes = s;
        vector<string> str;
        reverse(all(pes));
        for (int i = 0; i <= s.size(); i++) {
            temp1 = s;
            temp2 = s;
            reverse(temp1.begin(), temp1.begin() + i);
            if(i<s.size()){
            reverse(temp2.end() - i, temp2.end());
            }
            else {
                 reverse(temp2.end() - i, temp2.end()-1);
            }
            if (temp1 < temp2) {
                res = temp1;
                str.push_back(temp1);

            } else if (temp2 < temp1) {
                res = temp2;
                str.push_back(temp2);
            } else if (temp1 == temp2) {
                res = temp2;
                str.push_back(temp1);
            }
        }
        sort(all(str));
        return str[0];
    }
};