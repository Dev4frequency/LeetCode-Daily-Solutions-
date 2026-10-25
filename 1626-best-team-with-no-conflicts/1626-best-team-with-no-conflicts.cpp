class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size(), maxScore = 0;
        vector <pair <int, int> > player(n);
        vector <int> dp(n, 0);
        for(int i = 0; i < n; i++){
            player[i] = {ages[i], scores[i]};
        }

        sort(player.begin(), player.end());

        for(int i = 0; i < n; i++){
            dp[i] = player[i].second;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(player[j].second <= player[i].second){
                    dp[i] = max(dp[i], dp[j] + player[i].second);
                }
            }
            maxScore = max(maxScore, dp[i]);
        }

        return maxScore;
    }
};