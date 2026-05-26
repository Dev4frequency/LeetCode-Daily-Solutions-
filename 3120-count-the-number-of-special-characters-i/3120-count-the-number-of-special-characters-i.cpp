class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count = 0;
        sort(word.begin(), word.end());
        map<char, int> mp;
        for(auto x : word){
            if(x < 97) mp[x]++;
            else{
                char need = x - 32;
                if(mp.find(need) != mp.end()){
                    count++;
                    mp.erase(need);
                }
            }
        }
        return count;
    }
};