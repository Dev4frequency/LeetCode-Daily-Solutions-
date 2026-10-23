class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
      vector<int>ans;
      vector<vector<int>>v;
      
      if(veganFriendly)
        for(auto &r: restaurants){
          if(r[2] && r[3] <= maxPrice && r[4] <= maxDistance) v.push_back({r[1], r[0]});
        }
      else 
        for(auto &r: restaurants)
          if(r[3] <= maxPrice && r[4] <= maxDistance) v.push_back({r[1], r[0]});
          
      sort(v.begin(), v.end(), greater());
      for(auto &x: v) ans.push_back(x[1]);
          
      return ans;
    }
};