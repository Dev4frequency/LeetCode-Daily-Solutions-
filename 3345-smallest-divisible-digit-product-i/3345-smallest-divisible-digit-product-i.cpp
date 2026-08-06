class Solution {
public:
    int smallestNumber(int n, int t) {
        int prod=1;
        int dig;
        while(true)
        {
            dig=n;
            prod=1;
            while(dig>0)
            {
            prod=prod*(dig%10);
            dig=dig/10;
            }
            if(prod%t==0)return n;
            n++;
        }
        return prod;
    }
};