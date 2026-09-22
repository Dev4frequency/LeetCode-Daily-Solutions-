class Solution {
public:
    string minimizeStringValue(string s) { 
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int cnt[26] = {0};
        int n = s.size();
        string v = "";
        for(auto &x : s) 
            if(x != '?') 
                cnt[x - 'a']++;
        for(int i = 0; i < n; i++){
            if(s[i] == '?'){
                int mini = INT_MAX, c = -1;
                for(int j = 0; j < 26; j++) 
                    if(cnt[j] < mini) 
                        mini = cnt[j], c = j;
                cnt[c]++, v.push_back('a' + c);
            }
        }
        sort(v.begin(), v.end());
        for(int i = 0, j = 0; i < n; i++)
            if(s[i] == '?')
                s[i] = v[j++];         
        return s;
    }
};