class Cashier {
public:
    int m, dis;
    unordered_map<int,int> mp;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        m = n;
        dis = discount;
        for(int i=0 ; i<products.size() ; i++)
        {
            mp[products[i]] = prices[i];
        }
    }
    int count=0;
    double getBill(vector<int> product, vector<int> amount) {
        count++;
        double bill=0;
        for(int i=0 ; i<product.size() ; i++)
        {
            bill += mp[product[i]]*amount[i];
        }
        if(count==m)
        {
            bill = bill*(100-dis)/100;
            count=0;
        }
        return bill;
    }
};