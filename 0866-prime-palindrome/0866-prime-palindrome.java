class Solution {
    public int primePalindrome(int n) {
        if (n <= 2) {
            return 2;
        }
        if(n >= 9989900) return 100030001;
        if (n % 2 == 0) {
            n++;
        }
        while (true) {
            if (isPalindrome(n) && isPrime(n)) {
                return n;
            }
            n += 2;
        }
    }
    public static boolean isPrime(int n){
        if(n<= 1){
            return false;
        }
        for(int i = 2; i <= Math.sqrt(n); i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    public static boolean isPalindrome(int x){
        int rev = 0;
        int num = x;
        while(num >0){
            rev = 10*rev+num%10;
            num = num / 10;
        }
        return rev == x;
    }
}