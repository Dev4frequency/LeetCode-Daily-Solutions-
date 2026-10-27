class Solution {
public:
    int reinitializePermutation(int n) {
        ios_base::sync_with_stdio(0);
        vector<int>visited(n,false);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                int j = i,c = 0;
                while(!visited[j]){
                    c++;
                    visited[j] = true;
                    j = (j % 2 ? n / 2 + j / 2 : j / 2);
                }
                ans = max(ans,c);
            }
        }
        return ans;
    }
};