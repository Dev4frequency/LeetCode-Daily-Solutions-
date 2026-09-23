class Solution {
public:
    bool isVowel(char c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    string sortVowels(string s) {
        vector<char> vowels; 
       unordered_map<char, int> freq;
       for(auto v: s){
            if(isVowel(v)){
                freq[v]++;
                vowels.push_back(v);
            }
       }

       vector<char> unique;
       unordered_set<char> seen;
        for(auto v: vowels){
            if(!seen.count(v)){
                unique.push_back(v);
                seen.insert(v);
            }
        }
        sort(unique.begin(), unique.end(), [&](char a, char b){
            return freq[a] > freq[b];
        });

        vector<char> sorted;
        for(auto v: unique){
            for(int i = 0; i < freq[v]; i++){
                sorted.push_back(v);
            }
        }

        int pos = 0;
        for(int i = 0; i < s.size(); i++){
            if(isVowel(s[i])){
                s[i] = sorted[pos++];
            }
        }
        return s;
    }
};