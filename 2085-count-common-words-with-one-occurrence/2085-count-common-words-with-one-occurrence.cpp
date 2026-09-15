class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> m1, m2;
        for (auto &w : words1) m1[w]++;
        for (auto &w : words2) m2[w]++;
        
        int ans = 0;
        for (auto &[word, count] : m1) {
            if (count == 1 && m2[word] == 1) ans++;
        }
        return ans;
    }
};