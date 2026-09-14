class Solution {
public:
    int balancedStringSplit(string s) {
        int balance=0;
        int count=0;
        for(char ch:s){
            balance+=(ch=='L')?1:-1;
            if(balance==0) count++;
        }
        return count;
    }
};