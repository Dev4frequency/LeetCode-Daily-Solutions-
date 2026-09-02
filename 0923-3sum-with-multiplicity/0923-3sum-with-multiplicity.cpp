typedef long long ll;
class Solution {
public:
    int mod = 1e9+7;
    int threeSumMulti(vector<int>& arr, int target) {
        ll n = arr.size();
        int k =arr[0];
        
        sort(arr.begin(),arr.end());
        ll c = 0;

        for(ll a=0;a<n;a++){
            ll x = target - arr[a];
            ll i = a+1;
            ll j = n-1;

            while(i<j){
                ll sum = arr[i] + arr[j];
                if(sum == x){
                    if(arr[i]==arr[j]){
                        ll M = (j-i+1)*(j-i)/2;
                        c+=M;
                        c%=mod;
                        break;
                    }
                    ll previ = i;
                    i++;
                    while(i<=j && arr[i]==arr[previ]){
                        i++;
                    }
                    ll c1 = i - previ;
                    ll prevj = j;
                    j--;
                    while(j>=previ && arr[j]==arr[prevj]){
                        j--;
                    }
                    ll c2 = prevj - j;
                    
                    c =(c%mod + (c1*c2)%mod)%mod;
                }
                else if(sum > x){
                    j--;
                }
                else{
                    i++;
                }
            }
        }
        return c;
    }
};