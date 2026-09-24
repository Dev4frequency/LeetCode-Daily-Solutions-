class Solution{
public:
    int minChanges(vector<int>& nums,int k){
        const int U=1<<10,INF=1e9;
        int n=nums.size();
        vector<int> dp(U,INF),ndp(U);
        dp[0]=0;
        for(int g=0;g<k;g++){
            vector<int> freq(U);
            int cnt=0;
            for(int i=g;i<n;i+=k){
                freq[nums[i]]++;
                cnt++;
            }
            int mn=*min_element(dp.begin(),dp.end());
            for(int t=0;t<U;t++) ndp[t]=mn+cnt;
            for(int x=0;x<U;x++){
                if(!freq[x]) continue;
                int change=cnt-freq[x];
                for(int t=0;t<U;t++){
                    ndp[t]=min(ndp[t],dp[t^x]+change);
                }
            }
            dp.swap(ndp);
        }
        return dp[0];
    }
};