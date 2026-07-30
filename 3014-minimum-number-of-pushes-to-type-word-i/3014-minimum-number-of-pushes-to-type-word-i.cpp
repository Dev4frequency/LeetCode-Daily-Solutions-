class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        if(n<=8) return n;
        int ans = 0;
        int cnt = 1;
        for(int i = 1; i<=n/8; i++){
            ans+=i*8; cnt++;
        }
        ans += (n%8)*cnt;
        return ans;
    }
};