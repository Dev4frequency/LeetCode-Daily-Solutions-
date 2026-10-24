class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        int s = 0;
        sort(piles.begin(), piles.end());

        int k = n / 3;

        for(int i = n - 2; k > 0; i =i-2, k--) {
            s += piles[i];
        }

        return s;
    }
};