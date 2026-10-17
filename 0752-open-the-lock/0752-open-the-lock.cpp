class Solution {
public:
    int bfs(vector<string>& deadends, string target, unordered_set<string>& st) {
        if (st.count(target)||st.count("0000"))
            return -1;
        if ("0000" == target)
            return 0;
   
        queue<string> q;
        q.push("0000");
        int level = 1;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                string s = q.front();
                q.pop();
                st.insert(s);
                if (s == target)
                    return level;
                for (int j = 0; j < 4; j++) {
                    char original = s[j];
                    s[j] = (s[j] == '9') ? '0' : s[j] + 1;
                    if (s == target)
                        return level;
                    if (!st.count(s)) {
                        st.insert(s);
                        q.push(s);
                    }
                    s[j] = original;
                    s[j] = (s[j] == '0') ? '9' : s[j] - 1;
                    if (s == target)
                        return level;
                    if (!st.count(s)) {
                        st.insert(s);
                        q.push(s);
                    }
                    s[j] = original;
                }

            }
            level++;
        }
        return -1;
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st(deadends.begin(), deadends.end());
        return bfs(deadends, target, st);
    }
};