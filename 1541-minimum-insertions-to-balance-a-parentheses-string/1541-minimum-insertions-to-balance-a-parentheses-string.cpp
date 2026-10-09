class Solution {
public:
    int minInsertions(string v) {
        int c = 0;
        stack<char> p;
        string s;
        for (int i = 0; i < v.size() ; i++) {
            if (i+1<v.size()&&v[i] == ')' && v[i + 1] == ')') {
                s.push_back('}');
                i++;
            } else
                s.push_back(v[i]);
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                p.push('(');
            else if (s[i] == '}' && !p.empty())
                p.pop();
            else if (s[i] == '}' && p.empty())
                c++;
            else if (s[i] == ')' && p.empty())
                c += 2;
            else if (s[i] == ')' && !p.empty()) {
                c++;
                p.pop();
            }
        }
        while (!p.empty()) {
            c += 2;
            p.pop();
        }
        return c;
    }
};