class Solution {
public:
  
  int calculate_freq(string &w){
    char ch = 'z';
    int x = 0;
    
    for(auto &c: w)
      if(c == ch) x++;
      else if(c < ch) ch = c, x = 1;
    
    return x;
  }
  
  
  vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words){
    map<int, int> mp;                                      // <frecuence, number of words with the same frecuence>
    
    for(auto &w: words) mp[calculate_freq(w)]++;
    
    int sum = 0;
    
    for(auto it = mp.rbegin(); it != mp.rend(); it++){     //trunsform into  <frecuence, number of words with the same frecuence and large frequence>
      sum += it->second;
      mp[it->first] = sum;
    }
    
    vector<int> answer;
    
    for(auto &q: queries){
      auto id = mp.upper_bound(calculate_freq(q));
      if(id != mp.end()) answer.push_back((*id).second);
      else answer.push_back(0);
    }
    
    return answer;
  }
};