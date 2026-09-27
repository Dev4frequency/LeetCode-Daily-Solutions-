class Solution {
public:
    vector<string> findWords(vector<string>& words) {
    unordered_set<char> row1 = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
    unordered_set<char> row2 = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
    unordered_set<char> row3 = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};
    
    vector<string> result;
    for(string word : words){
        string lower_word = "";
        for(char c : word) lower_word += tolower(c);

        unordered_set<char> wordset(lower_word.begin(),lower_word.end());

        if(all_of(wordset.begin(),wordset.end(),[&] (char c){return row1.count(c);}) || 
        all_of(wordset.begin(),wordset.end(),[&] (char c){return row2.count(c);}) || 
        all_of(wordset.begin(),wordset.end(),[&] (char c){return row3.count(c);}))

        result.push_back(word);
    }

    
    return result;

    }
};