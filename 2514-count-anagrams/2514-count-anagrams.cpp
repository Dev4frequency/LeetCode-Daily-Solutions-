class Solution {
public:
    #define ll long long
    ll mod = 1e9+7LL;
    ll fact[100005] = {1LL}; 
    void initialize(){
        for(ll i = 1LL; i <= 100000; i++){
            fact[i] = (fact[i-1] * i) % mod;
        }
    }
    ll binexp(ll x){
        ll y = mod - 2LL, ans = 1LL;
        while(y){
            if(y & 1LL){
                ans = (ans * x) % mod;
            }
            x = (x * x) % mod;
            y >>= 1LL;
        }
        return ans;
    }
    int countAnagrams(string s) {
        ios_base::sync_with_stdio(0);
        initialize();
        int n = s.size();
        ll ans = 1LL,l = 0; vector<ll>c(26,0);
        for(int i = 0; i < n; i++){
            if(s[i] == ' '){
                ll val = fact[l];
                for(ll j = 0; j < 26; j++){
                    if(c[j]){
                        val = (val * binexp(fact[c[j]])) % mod;
                    }
                    c[j] = 0LL;
                }
                ans = (ans * val) % mod;
                l = 0;
            }
            else{
                l++;
                c[s[i]-'a']++;
            }
        }
        ll val = fact[l];
        for(ll j = 0; j < 26; j++){
            if(c[j]){
                val = (val * binexp(fact[c[j]])) % mod;
            }
            c[j] = 0LL;
        }
        ans = (ans * val) % mod;
        return ans;
    }
};