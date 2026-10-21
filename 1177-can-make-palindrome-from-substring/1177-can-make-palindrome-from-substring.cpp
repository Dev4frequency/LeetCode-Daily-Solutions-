class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int mask = 0;
        vector<vector<int>> ps;
        vector<int> freq = vector<int>(26,0);
        ps.push_back(freq);
        for(auto &c:s){
            freq[c-'a']++;
            ps.push_back(freq);
        }
        vector<bool> res(queries.size(), false);
        vector<bool> r;
        int itr = 0;
        for(auto &q:queries){
            int cnt_odd = 0;
            vector<int> f(26,0);
            for(int idx = 0;idx<26;idx++){
                f[idx] = ps[q[1]+1][idx]-ps[q[0]][idx];
                cnt_odd+=(f[idx]%2==1);
            }
            res[itr] = cnt_odd <= (2 * q[2] + (q[1]-q[0]+1) % 2);
            itr++;
        }
        return res;
    }
};