class Solution {
public:
    bool isDigitorialPermutation(int n) {
        int fact[10];
        fact[0] = 1;
        for(int i = 1; i <= 9; i++) {
            fact[i] = fact[i - 1] * i;
        }
        long long sum = 0;
        int n1=n;
        while(n1>0){
            int digit = n1%10;
            sum += fact[digit];
            n1 = n1/10;
        }
        vector<int>count1(10,0);
        vector<int>count2(10,0);
        while(sum>0){
            count1[sum%10]++;
            sum /=10;
        }
        while(n>0){
            count2[n%10]++;
            n/=10;
        }
        return count1==count2;
    }
};