class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int len_a = 0, len_b = 0;

        for(int i = 0;i < s.size();i++){
            if(s[i] == 'a') len_a++;
            else len_b++;

            if(len_a == len_b){
                len_a = 0;
                len_b = 0;
            } else {
                if(len_a > len_b){
                    len_a -= len_b;
                    len_b = 0;
                } else {
                    len_b -= len_a;
                    len_a = 0;
                }
            }
        }

        if(!len_a) return len_b;
        return len_a;
    }
};