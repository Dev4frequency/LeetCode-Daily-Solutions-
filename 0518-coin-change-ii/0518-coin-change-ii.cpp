class Solution {
public:
    int change(int amount, vector<int>& arr) {
       int n = arr.size();
       int modulo = 1e9+7;
       vector<long long> prev(amount + 1, 0), curr(amount + 1, 0);
        
        for(int j = 0; j <= amount; j++){
            if(j % arr[0] == 0)prev[j] = 1;
            else prev[j] = 0;
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j <= amount; j++){
                int pick = 0;
                if(j - arr[i] >= 0)pick = curr[j-arr[i]];

                int notPick = prev[j];
                curr[j] = (1LL*pick + notPick);
            }
            prev = curr;
        }
        return prev[amount];
    }
};