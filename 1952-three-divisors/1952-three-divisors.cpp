class Solution {
public:
    bool isThree(int n) {
      int divisors=2;
        for(int i=2;i<n;i++){
            if(n%i==0)
             divisors++;
            if(divisors>3)
             return false;
        }
       if(divisors==3)
              return true;
       return false;
    }
};