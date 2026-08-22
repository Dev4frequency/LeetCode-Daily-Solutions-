#define ll long long
class Solution {
public:
    long long maxGCDScore(vector<int>& v, int k) {
        ll ans=0,n=v.size();
        vector<ll>pow2(n,0);
        ll tmp;
        for(int i=0;i<n;i++){
            tmp=v[i];
            while((tmp%2)==0){
                pow2[i]++;
                tmp/=2;
            }
        }
        for(int i=0;i<n;i++){
            int g=v[i];
            ll minn=pow2[i],greats=0;
            for(int j=i;j<n;j++){
                ll len=j-i+1;
                if(pow2[j]<minn){
                    minn=pow2[j];
                    greats=len-1;
                }
                else if(pow2[j]>minn){
                    greats++;
                }
                g= __gcd(g,v[j]);
                if((len-greats)<=k)
                    ans=max(ans,(ll)g*len*2LL);
                else
                    ans=max(ans,g*len*1LL);
            }
        }
        return ans;
    }
};