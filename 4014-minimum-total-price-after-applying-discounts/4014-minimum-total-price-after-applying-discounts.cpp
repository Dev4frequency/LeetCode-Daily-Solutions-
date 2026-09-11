class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end(),greater<int>());
        sort(discounts.begin(),discounts.end(),greater<int>());
        double ans=0;
        int i=0;
        for(;i<prices.size()&&i<discounts.size();i++){
            ans+=prices[i]*(100-discounts[i])/100.0;
        }
        while(i<prices.size()){
           ans+=prices[i];
            i++;
        }
            
        return ans;
    }
};