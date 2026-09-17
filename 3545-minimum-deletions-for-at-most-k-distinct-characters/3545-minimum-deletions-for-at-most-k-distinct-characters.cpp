class Solution {

public:
    int minDeletion(const string& s, int k) {
      array<int, 26> freq {};
      for (auto ch : s) freq[ch - 'a']++;
      sort(begin(freq), end(freq));
      
      int distinct = 26 - (upper_bound(cbegin(freq), cend(freq), 0) - cbegin(freq));
      int res = 0;
      for (int i = 26 - distinct; i < 26 && distinct > k; i++, distinct--) {
        res += freq[i];
      }

      return res;
    }
};