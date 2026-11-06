class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        ios_base::sync_with_stdio(0);
        vector<pair<int,int>>q,p;
        int m = logs.size(),val = n;
        vector<int>ans(n,0); 
        n = queries.size(); vector<int>cnt(n,0);
        for(int i = 0; i < m; i++){
            q.push_back({logs[i][1],logs[i][0]});
        }
        for(int i = 0; i < n; i++){
            p.push_back({queries[i],i});
        }
        sort(q.begin(),q.end());
        sort(p.begin(),p.end());
        int i = 0,j = 0,c = 0;
        for(int k = 0; k < n; k++){
            while(j < m && q[j].first <= p[k].first){
                if(!ans[q[j].second-1]){
                    c++;
                }
                ans[q[j].second-1]++;
                j++;
            }
            while(i < m && q[i].first < p[k].first - x){
                ans[q[i].second-1]--;
                if(!ans[q[i].second-1]){
                    c--;
                }
                i++;
            }
            cnt[p[k].second] = val - c;
        }
        return cnt;
    }
};