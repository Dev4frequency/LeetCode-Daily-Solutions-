class Solution {
public:
    bool judgeSquareSum(int c) {
        long long a=0;
        long long b=sqrt(c);
        while(a<=b)
        {
            if(a*a+b*b==c)
            {
                return true;
            }
            if(a*a+b*b<c)
            {
                a++;
            }
            else{
                b--;
            }
        }
        return false;
    }
};