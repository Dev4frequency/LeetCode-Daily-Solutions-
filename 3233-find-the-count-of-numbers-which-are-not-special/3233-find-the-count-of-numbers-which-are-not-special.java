class Solution {
public int nonSpecialCount(int l, int r) {
        int SpecialCount=0;    

        int sqrt=(int)Math.sqrt(l);
        int minDivisor=(sqrt==1)? 2 : sqrt;
        for(int n=minDivisor; n*n<=r; n++){  
            if(isPrime(n)){                
                if(n*n>=l && n*n<=r){
                    SpecialCount++;
                }
            }
        }
        return (r-l+1)-SpecialCount;
    }
    boolean isPrime(int num){
        for(int i=2; i<=Math.sqrt(num); i++){
            if(num%i==0){
                return false;
            }
        }
        return true;
    }

}