class Solution {
public:
    long long countPairs(vector<string>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        if(n == 1)return 0;
        if(m == 1){
            return ((long long)n *(n-1))/2;
        }
        unordered_map<string,int>mp;
        long long count = 0;
        string s;
        s.reserve(m);
        for(int i = 0; i < n; i++){
            s.clear();
            int res = arr[i][0] - 'a';
            for(int j = 0; j < m; j++){
               int a = (arr[i][j] - 'a') - res;
               int modu = (a + 26) % 26;
               s += (char)('a'+modu);
            }
            count += mp[s];
            mp[s]++;
        }
        return count;
    }
};