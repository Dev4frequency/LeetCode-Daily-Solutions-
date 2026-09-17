#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string majorityFrequencyGroup(string s) {
        vector<int> f(26, 0);
        for(char c : s) f[c - 'a']++;

        unordered_map<int, vector<char>> m;
        for(int i = 0; i < 26; i++) {
            if(f[i] > 0) m[f[i]].push_back('a' + i);
        }

        int mx = 0, mf = 0;
        for(auto &p : m) {
            int k = p.first;
            int sz = p.second.size();
            if(sz > mx || (sz == mx && k > mf)) {
                mx = sz;
                mf = k;
            }
        }

        string ans;
        for(char c : m[mf]) ans.push_back(c);
        return ans;
    }
};