class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, long long> m;
        for(int i : time) m[i % 60]++;

        long long ans = 0, i = 1, j = 59;
        if(m[0] > 1) ans += (m[0] * (m[0] - 1)) / 2;
        if(m[30] > 1) ans += (m[30] * (m[30] - 1)) / 2;
        while(i < j) {
            if(m[i] && m[j]) ans += m[i] * m[j];
            i++, j--;
        }
        return ans;
    }
};