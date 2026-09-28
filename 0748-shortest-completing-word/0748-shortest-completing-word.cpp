class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char, int> licensePlateFreq;
        for (char c : licensePlate) {
            if (isalpha(c)) {
                licensePlateFreq[tolower(c)]++;
            }
        }

        string shortest_Word;
        int minLength = INT_MAX;

        for (const string& word : words) {
            unordered_map<char, int> wordFreq;
            
            for (char c : word) {
                wordFreq[c]++;
            }
            
            bool isCompleting = true;
            for (const auto& entry : licensePlateFreq) {
                char letter = entry.first;
                int requireCount = entry.second;
                int wordCount = wordFreq[letter];
                
                if (wordCount < requireCount) {
                    isCompleting = false;
                    break;
                }
            }

            if (isCompleting && word.length() < minLength) {
                shortest_Word = word;
                minLength = word.length();
            }
        }
        
        return shortest_Word;
    }
};
