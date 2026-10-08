class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        if(prices.size() == 1) return money;
        sort(prices.begin(),prices.end());
        if((prices[0] + prices[1]) > money)
        return money;
        else
        return money -(prices[0] + prices[1]);
    }
};