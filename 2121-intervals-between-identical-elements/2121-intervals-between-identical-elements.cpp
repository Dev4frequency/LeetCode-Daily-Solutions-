class Solution 
{
public:
    vector<long long> getDistances(vector<int>& arr) 
    {
        int n=arr.size();
        vector<long long> ans(n,0);

        map<int,long long> before, after;

        map<int,long long> m;
        map<int,long long> cnt;
        map<int,long long> cnt1;

        for(int x=0; x<n; x++)
        {
            before[x]=m[arr[x]];
            m[arr[x]]+=x;
            cnt1[x]=cnt[arr[x]];
            cnt[arr[x]]++;
        }

        map<int,long long> m1;
        map<int,long long> cnt2;
        map<int,long long> cnt3;

        for(int x=n-1; x>=0; x--)
        {
            after[x]=m1[arr[x]];
            m1[arr[x]]+=x;
            cnt3[x]=cnt2[arr[x]];
            cnt2[arr[x]]++;
        }

        for(int x=0; x<n; x++)
        {
            ans[x]=(long long)cnt1[x]*x-before[x]+after[x]-(long long)cnt3[x]*x;
        }
        return ans;
    }
};