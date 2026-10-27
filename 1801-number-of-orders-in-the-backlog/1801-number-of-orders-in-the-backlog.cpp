class Solution {
public:
  int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
    map<int, long> buy, sell;
    
    for(auto &it: orders) 
      if(it[2]){
        auto b = buy.rbegin();
        while(b != buy.rend() && it[0] <= b->first){
          it[1] -= b->second;
          if(it[1] <  0) {b->second = -it[1]; break;}
          
          int tmp = b->first; 
          b++;                                          
          buy.erase(tmp);
          if(it[1] == 0) break;
        }
        if(it[1] > 0) sell[it[0]] += it[1];
      }
      else {  
        auto s = sell.begin();
        while(s != sell.end() && it[0] >= s->first){
          it[1] -= s->second;
          if(it[1] <  0) {s->second = -it[1]; break;}
          
          int tmp = s->first;
          s++;
          sell.erase(tmp);
          if(it[1] == 0) break;
        }
        if(it[1] > 0) buy[it[0]] += it[1];
      } 
      
    
    long answer = 0;
    for(auto &it: buy ) answer += it.second;
    for(auto &it: sell) answer += it.second;
    
    return answer % 1000000007;
  }
};