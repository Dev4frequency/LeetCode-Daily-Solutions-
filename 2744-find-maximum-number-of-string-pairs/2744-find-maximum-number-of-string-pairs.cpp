class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string> s;
        for (int i = 0; i < words.size(); i++) {
            s.insert(words[i]);
        }

        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            string val = words[i];
            reverse(val.begin(), val.end());

            if (val != words[i]) {
                if (s.find(val) != s.end()) {
                    count++;
                    s.erase(words[i]);
                }
            }
        }

        return count;
    }
};