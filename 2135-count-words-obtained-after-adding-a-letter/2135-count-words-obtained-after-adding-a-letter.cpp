class Solution {
public:
  int wordCount(vector<string>& startWords, vector<string>& targetWords) {
    unordered_map<unsigned int, int>t;
    
    for(auto &w: targetWords){
      unsigned int n = 0;
      for(auto ch: w) n |= (1<<(ch-'a')); 
      t[n]++;
    }
    
    int ans = 0;
    
    for(auto &w: startWords){
      unsigned int n = 0;
      for(auto ch: w) n |= (1<<(ch-'a'));
     
      for(int i = 0, mask = 1; i != 26; i++, mask = mask<<1)
        if( (mask & n) == 0){
          unsigned simple = n|mask; 
          
          if(t.count(simple)){
            ans += t[simple];
            t.erase(simple);
          }
        }
    }
    
    return ans;
  }
};
