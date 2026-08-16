class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int cnt = 0;
        for(int i=0; i<s.size(); i++){
            int vowel = 0;
            int consonant = 0;
            for(int j=i; j<s.size(); j++){
                if(vowels.find(s[j]) != vowels.end()) vowel++;
                else consonant++;
                if(vowel != 0 && consonant != 0 && vowel == consonant && (vowel*consonant)%k==0) cnt++;
            }
        }
        return cnt;
    }
};