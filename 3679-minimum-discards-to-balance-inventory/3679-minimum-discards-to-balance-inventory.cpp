class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arr, int w, int m) {
        int i=0;
        int n = arr.size();
        int ans = 0;
        unordered_map<int,int> mp;
        for(int j=0;j<n;j++) {
            while(j-i+1>w) {
                mp[arr[i]]--;
                i++;
            }

            if(j-i+1<=w && mp[arr[j]]+1 > m) {
                arr[j]=0;
                ans++;
                continue;
            }
            
            mp[arr[j]]++;
        }
        return ans;
    }
};