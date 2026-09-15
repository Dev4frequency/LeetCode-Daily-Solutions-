class Solution {
public:
    bool digitCount(string num) {
        int freq[10] = {0};
        for(char i : num) {
            freq[i - '0']++;
        }
        for(int i = 0; i < num.size(); i++) {
            if(freq[i] != (num[i] - '0')) {
                return false;
            }
        }

        return true;
    }
};